
#include <stdio.h>
#include <string.h>

int romanToInt(char *s) {
    int result = 0;
    int prev = 0;

    for (int i = strlen(s) - 1; i >= 0; i--) {
        int current;

        switch (s[i]) {
            case 'I': current = 1; break;
            case 'V': current = 5; break;
            case 'X': current = 10; break;
            case 'L': current = 50; break;
            case 'C': current = 100; break;
            case 'D': current = 500; break;
            case 'M': current = 1000; break;
            default: return -1; // Invalid character
        }

        if (current < prev) {
            result -= current;
        } else {
            result += current;
        }

        prev = current;
    }

    return result;
}

int main() {
    char roman[16];
    printf("Enter Roman numeral: ");
    scanf("%s", roman);

    int integer = romanToInt(roman);

    if (integer == -1) {
        printf("Invalid Roman numeral.\n");
    } else {
        printf("Integer equivalent: %d\n", integer);
    }

    return 0;
}