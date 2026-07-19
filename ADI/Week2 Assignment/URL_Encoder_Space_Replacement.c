/*
Question:
29. URL Encoder (Space Replacement)
Write a C function void url_encode(char *str, int true_length) that replaces all spaces in a string with "%20". Assume the string has sufficient buffer space at the end to hold the additional characters, and you are given the "true" length of the initial string.

Input: "Hello World  ", true_length = 11
Output: "Hello%20World"
*/
#include <stdio.h>

void url_encode(char *str, int true_length) {
    int space_count = 0;

    // Count spaces in the true string
    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ') {
            space_count++;
        }
    }

    int new_length = true_length + (space_count * 2);

    str[new_length] = '\0';

    for (int i = true_length - 1, j = new_length - 1; i >= 0; i--) {

        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
    }
}

int main() {
    char str[30] = "Hello World";

    url_encode(str, 11);

    printf("%s\n", str);

    return 0;
}

/*
Output: Hello%20World
*/
