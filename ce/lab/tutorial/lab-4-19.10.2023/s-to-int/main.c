#include <stdio.h>
#include <stdlib.h>

void uintToString(unsigned int number, char **result) {
    if (number == 0) {
        *result = (char *) malloc(2 * sizeof(char));
        if (*result == NULL) {
            printf("Memory allocation error.\n");
            exit(1);
        }
        (*result)[0] = '0';
        (*result)[1] = '\0';
        return;
    }

    int length = 0;
    unsigned int temp = number;
    while (temp > 0) {
        temp /= 10;
        length++;
    }

    *result = (char *) malloc((length + 1) * sizeof(char));
    if (*result == NULL) {
        printf("Whats wrong with your memory???\n");
        exit(1);
    }

    int index = length - 1;
    while (number > 0) {
        int digit = number % 10;
        (*result)[index] = '0' + digit;
        number /= 10;
        index--;
    }
    (*result)[length] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <unsigned_integer>\n", argv[0]);
        return 1;
    }

    unsigned int number = atoi(argv[1]);

    char *result = NULL;
    uintToString(number, &result);

    printf("Result of conversion: %s\n", result);

    free(result);

    return 0;
}
