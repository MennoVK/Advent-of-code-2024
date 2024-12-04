#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELENGTH 140

void main() {
    FILE *file;

    file = fopen("input.txt", "r");

    if (!file) {
        perror("Could not open file");
        return;
    }

    char line[LINELENGTH+2];
    char input[LINELENGTH][LINELENGTH+2];
    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        strcpy(input[count], line);
        count += 1;
    }

    int totalCount = 0;

    for(int i = 0; i < count; i++){
        for (int j = 0; j < LINELENGTH; j++){
            if(input[i][j] == 'X'){
                // Check for "XMAS"
                if (j + 3 < LINELENGTH && input[i][j+1] == 'M' && input[i][j+2] == 'A' && input[i][j+3] == 'S'){
                    totalCount += 1;
                }
                // Check for "X" vertical pattern
                if (i + 3 < count && input[i+1][j] == 'M' && input[i+2][j] == 'A' && input[i+3][j] == 'S'){
                    totalCount += 1;
                }
                // Check for "XMAS" diagonal pattern (down-right)
                if (i + 3 < count && j + 3 < LINELENGTH && input[i+1][j+1] == 'M' && input[i+2][j+2] == 'A' && input[i+3][j+3] == 'S'){
                    totalCount += 1;
                }
                // Check for "XMAS" diagonal pattern (up-right)
                if (i + 3 < count && j - 3 >= 0 && input[i+1][j-1] == 'M' && input[i+2][j-2] == 'A' && input[i+3][j-3] == 'S'){
                    totalCount += 1;
                }
            }
            if(input[i][j] == 'S'){
                // Check for "SAMX"
                if (j + 3 < LINELENGTH && input[i][j+1] == 'A' && input[i][j+2] == 'M' && input[i][j+3] == 'X'){
                    totalCount += 1;
                }
                // Check for "SAMX" vertical pattern
                if (i + 3 < count && input[i+1][j] == 'A' && input[i+2][j] == 'M' && input[i+3][j] == 'X'){
                    totalCount += 1;
                }
                // Check for "SAMX" diagonal pattern (down-right)
                if (i + 3 < count && j + 3 < LINELENGTH && input[i+1][j+1] == 'A' && input[i+2][j+2] == 'M' && input[i+3][j+3] == 'X'){
                    totalCount += 1;
                }
                // Check for "SAMX" diagonal pattern (up-right)
                if (i + 3 < count && j - 3 >= 0 && input[i+1][j-1] == 'A' && input[i+2][j-2] == 'M' && input[i+3][j-3] == 'X'){
                    totalCount += 1;
                }
            }
        }
    }
    printf("%d\n", totalCount);

    fclose(file);
}
