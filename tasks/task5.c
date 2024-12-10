#include <stdio.h>

int string_compare(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No words to count.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        int count = 0;
        int already_counted = 0;

        for (int j = 1; j < i; j++) {
            if (string_compare(argv[i], argv[j]) == 0) {
                already_counted = 1;
                break;
            }
        }

        if (already_counted) {
            continue;
        }
        for (int j = 1; j < argc; j++) {
            if (string_compare(argv[i], argv[j]) == 0) {
                count++;
            }
        }
        printf("%s: %d\n", argv[i], count);
    }
    return 0;
}
