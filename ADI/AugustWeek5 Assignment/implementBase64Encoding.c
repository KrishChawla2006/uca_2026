#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base64Table[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

char* base64Encode(const char* input) {
    int len = strlen(input);

    int outputLen = 4 * ((len + 2) / 3);

    char* output = malloc(outputLen + 1);

    if (output == NULL)
        return NULL;

    int i = 0;
    int j = 0;

    while (i < len) {
        unsigned char b1 = input[i++];
        unsigned char b2 = (i < len) ? input[i++] : 0;
        unsigned char b3 = (i < len) ? input[i++] : 0;

        unsigned int bits =
            ((unsigned int)b1 << 16) |
            ((unsigned int)b2 << 8) |
            b3;

        output[j++] = base64Table[(bits >> 18) & 0x3F];
        output[j++] = base64Table[(bits >> 12) & 0x3F];

        if (i - 1 <= len) {
            if (i - 1 < len + 1)
                output[j++] = base64Table[(bits >> 6) & 0x3F];
        }

        if (i <= len)
            output[j++] = base64Table[bits & 0x3F];

        // Correct padding
        if (i - 1 > len)
            output[j - 1] = '=';

        if (i > len)
            output[j - 1] = '=';
    }

    output[j] = '\0';

    return output;
}

int main() {
    const char* input = "Man";

    char* encoded = base64Encode(input);

    if (encoded != NULL) {
        printf("Input  : %s\n", input);
        printf("Base64 : %s\n", encoded);

        free(encoded);
    }

    return 0;
}
