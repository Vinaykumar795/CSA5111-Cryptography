#include <stdio.h>
#include <string.h>
int main(void){
    const char bits[]="10101010";
    const int block_size=8;
    int padding=block_size-(int)strlen(bits)%block_size;
    printf("Input: %s\nPadded: %s1",bits,bits);
    for(int i=1;i<padding;i++)putchar('0');
    printf("\nPadding length=%d\n",padding);
    puts("Always adding padding lets the receiver distinguish the original data.");
    return 0;
}
