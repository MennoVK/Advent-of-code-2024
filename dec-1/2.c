#include <stdio.h>

#define AMOUNT_OF_LINES 1000

int CountAmountOfAppearances(int input[], int numberToCheck);

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

    int totalCount = 0;

    for(int i = 0; i < AMOUNT_OF_LINES; i++){
        int amount = CountAmountOfAppearances(array2, array1[i]);
        totalCount += array1[i] * amount;
    }

    printf("%i", totalCount);

}

int CountAmountOfAppearances(int input[], int numberToCheck){
    int counter = 0;
    
    for(int i = 0; i < AMOUNT_OF_LINES; i++){
        if(input[i] == numberToCheck){
            counter += 1;
        };
    }

    return counter;
}