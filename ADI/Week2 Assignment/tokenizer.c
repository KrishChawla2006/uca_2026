/*
Question:
25. The Tokenizer
Write a C code snippet using strtok() that takes the string "C,C++,Java,Python,Rust" and prints each language on a new line. Please submit your solution by providing a GitHub file link.
*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "C,C++,Java,Python,Rust";
    //strtok() searches for the first comma.Then it replaces the comma with '\0'.
    char *token = strtok(str, ",");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}

/*
Output:
C
C++
Java
Python
Rust
*/
