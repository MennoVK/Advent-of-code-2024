#include <stdio.h>
#include <stdlib.h>

#define AMOUNT_OF_LINES 1000

int comp(const void* a, const void* b);

void main(){
    FILE *file;

    file = fopen("input.txt", "r");

    if (!file) {
        perror("Could not open file");
        return;
    }

    int array1[AMOUNT_OF_LINES];
    int array2[AMOUNT_OF_LINES];

    int num1, num2;

    int index = 0;

    while(fscanf(file, "%d %d", &num1, &num2) == 2) {
        array1[index] = num1;
        array2[index] = num2;
        index++;
    }
    
    fclose(file);

    qsort(array1, AMOUNT_OF_LINES, sizeof(int), comp);
    qsort(array2, AMOUNT_OF_LINES, sizeof(int), comp);

    int totalCount = 0;

    for(int i = 0; i < AMOUNT_OF_LINES; i++){
        int absDifference = abs(array1[i] - array2[i]);
        totalCount += absDifference;
    }

    printf("%i", totalCount);
}

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}