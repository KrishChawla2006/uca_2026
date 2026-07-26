#include <stdio.h>

int main() {
    int c, next;

    while ((c = getchar()) != EOF) {

        
        if (c == '"') {
            putchar(c);
            while ((c = getchar()) != EOF) {
                putchar(c);
                if (c == '\\') {          
                    c = getchar();
                    if (c != EOF)
                        putchar(c);
                } else if (c == '"') {
                    break;
                }
            }
        }

        
        else if (c == '\'') {
            putchar(c);
            while ((c = getchar()) != EOF) {
                putchar(c);
                if (c == '\\') {          
                    c = getchar();
                    if (c != EOF)
                        putchar(c);
                } else if (c == '\'') {
                    break;
                }
            }
        }

        
        else if (c == '/') {
            next = getchar();

            // Single-line comment
            if (next == '/') {
                while ((c = getchar()) != EOF && c != '\n');
                if (c == '\n')
                    putchar('\n');
            }

            // Multi-line comment
            else if (next == '*') {
                int prev = 0;
                while ((c = getchar()) != EOF) {
                    if (prev == '*' && c == '/')
                        break;
                    prev = c;
                }
            }

            // Not a comment
            else {
                putchar(c);
                if (next != EOF)
                    putchar(next);
            }
        }

        // Normal character
        else {
            putchar(c);
        }
    }

    return 0;
}
