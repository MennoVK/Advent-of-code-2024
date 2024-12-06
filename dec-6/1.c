#include <stdio.h>
#include <string.h>

#define ROWS 130
#define COLS 130 

struct guardCurrentPoint{
    int rowIndex;
    int colIndex;
};

enum Direction{up, right, down, left};

void moveGuard(char col[ROWS][COLS + 2], struct guardCurrentPoint *guardCurrentPoint);
int calculateDistinctPositions(char col[ROWS][COLS+2]);

void main() {
    FILE *file;

    file = fopen("input.txt", "r");

    if (!file) {
        perror("Could not open file");
        return;
    }

    char row[COLS + 2];
    char col[ROWS][COLS + 2];
    int count = 0;
    struct guardCurrentPoint guardCurrentPoint;

    while (fgets(row, sizeof(row), file) != NULL) {
        strcpy(col[count], row);
        for(int i = 0; i < COLS + 2; i++){
            if(row[i] == '^'){
                guardCurrentPoint.rowIndex = count;
                guardCurrentPoint.colIndex = i;
            }
        }
        count += 1;
    }

    moveGuard(col, &guardCurrentPoint);

    int distinctPositions;    
    distinctPositions = calculateDistinctPositions(col);

    printf("\n%d", distinctPositions);

    fclose(file);
}

void moveGuard(char col[ROWS][COLS + 2], struct guardCurrentPoint *guardCurrentPoint) {
    enum Direction currentDirection = up;

    while (
            guardCurrentPoint->rowIndex <= ROWS     &&
            guardCurrentPoint->colIndex <= COLS - 2 &&
            0 <= guardCurrentPoint->colIndex        &&
            0 <= guardCurrentPoint->rowIndex
        ) switch (currentDirection) {
            case up:
                (col[guardCurrentPoint->rowIndex - 1][guardCurrentPoint->colIndex] == '#') 
                    ? (currentDirection = right) 
                    : (guardCurrentPoint->rowIndex -= 1, col[guardCurrentPoint->rowIndex][guardCurrentPoint->colIndex] = 'X');
                break;
            
            case right:
                (col[guardCurrentPoint->rowIndex][guardCurrentPoint->colIndex + 1] == '#') 
                    ? (currentDirection = down) 
                    : (guardCurrentPoint->colIndex += 1, col[guardCurrentPoint->rowIndex][guardCurrentPoint->colIndex] = 'X');
                break;
            
            case down:
                (col[guardCurrentPoint->rowIndex + 1][guardCurrentPoint->colIndex] == '#') 
                    ? (currentDirection = left) 
                    : (guardCurrentPoint->rowIndex += 1, col[guardCurrentPoint->rowIndex][guardCurrentPoint->colIndex] = 'X');
                break;
            
            case left:
                (col[guardCurrentPoint->rowIndex][guardCurrentPoint->colIndex - 1] == '#') 
                    ? (currentDirection = up) 
                    : (guardCurrentPoint->colIndex -= 1, col[guardCurrentPoint->rowIndex][guardCurrentPoint->colIndex] = 'X');
                break;
        }
}

int calculateDistinctPositions(char col[ROWS][COLS+2]){
    int totalCount = 1;
    
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS + 2; j++){
            printf("%c", col[i][j]);
            if(col[i][j] == 'X'){
                totalCount++;
            };
        }
    }

    return totalCount;
}