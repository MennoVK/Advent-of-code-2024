#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define RULECOUNT 1176
#define UPDATECOUNT 1367 - 1178 + 1


bool containsRule(char rule[], char update[]){
    char num1[3];
    char num2[3];
    
    strncpy(num1, rule, 2);
    strncpy(num2, rule + 3, 2);
    num1[2] = '\0';
    num2[2] = '\0';

    char *resultNum1 = strstr(update, num1);
    char *resultNum2 = strstr(update, num2);

    int positionNum1 = resultNum1 - update;
    int positionNum2 = resultNum2 - update;

    return (resultNum1 == 0 || resultNum2 == 0) || ((positionNum1 - positionNum2) < 0);
}

int getMiddleNumber(char update[]){
    char number[3];

    number[0] = update[(strlen(update)-2)/2];
    number[1] = update[(strlen(update)-1)/2];

    return atoi(number);
}

void main() {
    FILE *file;

    file = fopen("input.txt", "r");

    if (!file) {
        perror("Could not open file");
        return;
    }

    char rule[UPDATECOUNT + 1];
    int count = 0;

    char rules[RULECOUNT][UPDATECOUNT + 1];

    while (fgets(rule, sizeof(rule), file) != NULL) {
        if(count < RULECOUNT){
            strcpy(rules[count], rule);
        }
        count++;
    }

    rewind(file);
    count = 0;

    char update[250];

    int totalCount = 0;

    while (fgets(update, sizeof(update), file) != NULL) {
        if(count > RULECOUNT){
            int safe = 1;
            for (int i = 0; i < RULECOUNT; i++){
                if(!containsRule(rules[i], update)){
                    safe = 0;
                };
            }

            if(safe){
                totalCount += getMiddleNumber(update);
            }
        }
        count++;
    }

    printf("%d", totalCount);

    fclose(file);
}
