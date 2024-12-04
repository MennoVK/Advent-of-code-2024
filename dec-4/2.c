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

    for(int i = 1; i < count - 1; i++){
        for (int j = 1; j < LINELENGTH - 1; j++){
            if(input[i][j] == 'A'){
                if (input[i-1][j-1] == 'S' && input[i-1][j+1] == 'S' &&  input[i+1][j-1] == 'M' && input[i+1][j+1] == 'M' ||
                    input[i-1][j-1] == 'M' && input[i-1][j+1] == 'M' &&  input[i+1][j-1] == 'S' && input[i+1][j+1] == 'S' ||
                    input[i-1][j-1] == 'M' && input[i-1][j+1] == 'S' &&  input[i+1][j-1] == 'M' && input[i+1][j+1] == 'S' ||
                    input[i-1][j-1] == 'S' && input[i-1][j+1] == 'M' &&  input[i+1][j-1] == 'S' && input[i+1][j+1] == 'M')
                {
                    totalCount += 1;
                }
            }
        }
    }
    printf("%d\n", totalCount);

    fclose(file);
}
