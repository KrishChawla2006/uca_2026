/*
Question:
26. Custom Implementation (No <string.h>)
Write a custom C function int my_strlen(const char *str) that calculates and returns the length of a string without using the built-in strlen() function.
*/

#include <stdio.h>

int my_strlen(const char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    char str[] = "Hello, World!";

    printf("Length = %d\n", my_strlen(str));

    return 0;
}
