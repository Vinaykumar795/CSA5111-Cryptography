#include <stdio.h>
#include <string.h>
int main(void) {
    char bits[500] = "10101010";
    int block = 8, n = (int)strlen(bits);
    int padding = block - n % block;
    printf("Original: %s\nPadded: %s1", bits, bits);
    for (int i = 1; i < padding; i++) putchar('0');
    printf("\nPadding bits: %d\n", padding);
    puts("A full padding block removes ambiguity when the data length is already aligned.");
    return 0;
}
