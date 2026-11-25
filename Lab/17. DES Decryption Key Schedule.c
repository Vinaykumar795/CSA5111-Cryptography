#include <stdio.h>

int main() {
    int shift[16]={
        1,1,2,2,2,2,2,2,
        1,2,2,2,2,2,2,1
    };

    printf("Encryption key schedule:\n");

    for(int i=0;i<16;i++)
        printf("K%d: Left shift %d\n",i+1,shift[i]);

    printf("\nDecryption key schedule:\n");
    printf("K16: No initial shift\n");

    for(int i=15;i>0;i--)
        printf("K%d: Right shift %d\n",i,shift[i]);

    return 0;
}
