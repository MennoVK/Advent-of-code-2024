#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* createArray(char row[], int size, int* count);
bool isRowSafe(int* numbers, int* count);

void main() {
    FILE *file;

    file = fopen("input.txt", "r");

    if (!file) {
        perror("Could not open file");
        return;
    }
    
    char input[24];
    int totalSafe = 0;

    while(fgets(input, sizeof(input), file)) {
        int count = 0;
        
        int* numbers = createArray(input, 8, &count);

        bool isSafe = isRowSafe(numbers, &count);

        if (isSafe) {
            totalSafe += 1;
        }

        free(numbers);
    }
    fclose(file);

    printf("%d", totalSafe);
}

int* createArray(char row[], int size, int* count) {
    *count = 0;
    int* array = malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    size_t len = strlen(row);
    if (len > 0 && row[len - 1] == '\n') {
        row[len - 1] = '\0';
    }

    char *token = strtok(row, " ");
    while (token != NULL) {
        array[(*count)++] = atoi(token);
        token = strtok(NULL, " ");
    }

    return array;
}

bool isRowSafe(int* numbers, int* count){
    bool isSafe = true;
    int increaseOrDecrease = 0;

    for (int i = 0; i < *count - 1; i++) {
        int difference = abs(numbers[i] - numbers[i+1]);
        if(difference == 0 || difference > 3){
            isSafe = false;
            break;
        }
        else if(numbers[i] > numbers[i+1]){
            increaseOrDecrease += 1;
        }
        else if(numbers[i] < numbers[i+1]){
            increaseOrDecrease -= 1;
        }
    }

    if(!(increaseOrDecrease == *count -1 || increaseOrDecrease == -*count+ 1)){
        isSafe = false;
    }

    return isSafe;
}