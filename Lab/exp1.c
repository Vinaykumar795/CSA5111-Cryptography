#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int k, i;

    printf("Enter a string: ");
    scanf("%s", text);

    for (k = 1; k <= 25; k++) {
        printf("\nKey %d: ", k);

        for (i = 0; text[i] != '\0'; i++) {
            char ch = text[i];

            if (ch >= 'A' && ch <= 'Z')
                ch = (ch - 'A' + k) % 26 + 'A';
            else if (ch >= 'a' && ch <= 'z')
                ch = (ch - 'a' + k) % 26 + 'a';

            printf("%c", ch);
        }
    }

    return 0;
}
