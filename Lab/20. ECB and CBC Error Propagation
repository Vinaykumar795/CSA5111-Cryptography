#include <stdio.h>

int encrypt(int x) {
    return (5*x+8)&255;
}

int decrypt(int x) {
    return (205*(x-8))&255;
}

int main() {
    int p[]={1,2,3,4};
    int c[4],v=0;

    printf("Original plaintext: ");

    for(int i=0;i<4;i++)
        printf("%d ",p[i]);

    for(int i=0;i<4;i++)
        v=c[i]=encrypt(p[i]^v);

    c[0]^=1;
    v=0;

    printf("\nCBC after ciphertext error: ");

    for(int i=0;i<4;i++) {
        printf("%d ",decrypt(c[i])^v);
        v=c[i];
    }

    printf("\nECB after ciphertext error: ");

    for(int i=0;i<4;i++) {
        c[i]=encrypt(p[i]);

        if(i==0)
            c[i]^=1;

        printf("%d ",decrypt(c[i]));
    }

    return 0;
}
