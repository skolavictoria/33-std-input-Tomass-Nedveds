#include <stdio.h>

int string_compare(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

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
    if (argc != 4) {
        printf("Error: Please provide an operation and two numbers.\n");
        return 1;
    }

    const char *operation = argv[1];
    int num1 = parse_number(argv[2]);
    int num2 = parse_number(argv[3]);

    if (string_compare(operation, "add") == 0) {
        printf("Result: %d\n", num1 + num2);
    } 
    else if (string_compare(operation, "subtract") == 0) {
        printf("Result: %d\n", num1 - num2);
    } 
    
    else if (string_compare(operation, "multiply") == 0) {
        printf("Result: %d\n", num1 * num2);
    } 

    else if (string_compare(operation, "divide") == 0) {
        if (num2 == 0) {
            printf("Error: Division by zero is not allowed.\n");
            return 1;
        }
        printf("Result: %d\n", num1 / num2);
    } 
    else {
        printf("Error: Unsupported operation. Use add, subtract, multiply, or divide.\n");
        return 1;
    }
    return 0;
}