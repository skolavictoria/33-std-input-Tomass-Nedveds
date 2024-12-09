#include <stdio.h>

int parse_number(const char *str) {
    int result = 0;
    int i = 0;

    int is_negative = 0;
    if (str[i] == '-') {
        is_negative = 1;
        i++;
    }

    for (; str[i] != '\0'; i++) {
        result = result * 10 + (str[i] - '0');
    }
    return is_negative ? -result : result;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: Please provide exactly two numbers.\n");
        return 1;
    }

    int num1 = parse_number(argv[1]);
    int num2 = parse_number(argv[2]);
    printf("Sum: %d\n", num1 + num2);
    return 0;
}