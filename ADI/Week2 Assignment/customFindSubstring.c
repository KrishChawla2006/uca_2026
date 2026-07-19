/*
Question:
28. Substring Search (Custom strstr)
Implement your own version of the standard C strstr() function: int find_substring(const char *haystack, const char *needle). The function should return the starting index of the first occurrence of the needle string within the haystack string. If the needle is not found, return -1.

Input: haystack = "Embedded Systems", needle = "bed"
Output: 2 (since "bed" starts at index 2)
Constraint: Do not use any functions from <string.h>.
*/
#include <stdio.h>

int find_substring(const char *haystack, const char *needle) {
    int i, j;

    // If needle is empty, return 0
    if (needle[0] == '\0')
        return 0;

    // Traverse the haystack
    for (i = 0; haystack[i] != '\0'; i++) {

        // Compare characters of needle
        for (j = 0; needle[j] != '\0'; j++) {

            if (haystack[i + j] != needle[j]) {
                break;
            }
        }

        // If we reach the end of needle, it matched
        if (needle[j] == '\0') {
            return i;
        }
    }

    // Not found
    return -1;
}

int main() {
    char haystack[] = "Embedded Systems";
    char needle[] = "bed";

    int index = find_substring(haystack, needle);

    if (index != -1)
        printf(index);
    else
        printf("Substring not found\n");

    return 0;
}
/*
Output: 2
*/
