#include <stdio.h>
#include <string.h>
#include <limits.h>

#define FSIZE (5 << 12)

int numPlaces (int n);
int findMulOccurrences(const char *input);

void main() {
    FILE *file;

    file = fopen("input.txt", "r");

    if (!file) {
        perror("Could not open file");
        return;
    }

    static char input[FSIZE];
    
    fread(input, sizeof input, 1, file);

    int totalCount = 0;
    totalCount += findMulOccurrences(input);

    printf("%d", totalCount);

    fclose(file);
}

int numPlaces (int n) {
    if (n < 0) return numPlaces ((n == INT_MIN) ? INT_MAX: -n);
    if (n < 10) return 1;
    return 1 + numPlaces (n / 10);
}

int findMulOccurrences(const char *input) {
    const char *cursor = input;
    const char *pattern = "mul(";
    int countInLine = 0;

    while ((cursor = strstr(cursor, pattern)) != NULL) {
        int x, y;

        int index = cursor - input;

        if (sscanf(cursor, "mul(%d,%d)", &x, &y) == 2) {
            if(input[index + numPlaces(x) + numPlaces(y) + 5] == ')'){
                countInLine += x * y;
            };
        }
        cursor += 4;
    }

    return countInLine;
}