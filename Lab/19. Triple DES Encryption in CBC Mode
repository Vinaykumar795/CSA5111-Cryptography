#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main() {
    DES_cblock k1="12345678";
    DES_cblock k2="ABCDEFGH";
    DES_cblock k3="87654321";
    DES_cblock iv={0};

    DES_key_schedule s1,s2,s3;

    unsigned char p[16]="HELLO WORLD";
    unsigned char c[16],d[16];

    DES_set_key_unchecked(&k1,&s1);
    DES_set_key_unchecked(&k2,&s2);
    DES_set_key_unchecked(&k3,&s3);

    DES_ede3_cbc_encrypt(
        p,c,16,&s1,&s2,&s3,&iv,DES_ENCRYPT
    );

    printf("Encrypted: ");

    for(int i=0;i<16;i++)
        printf("%02X ",c[i]);

    memset(iv,0,8);

    DES_ede3_cbc_encrypt(
        c,d,16,&s1,&s2,&s3,&iv,DES_DECRYPT
    );

    printf("\nDecrypted: %s\n",d);

    return memcmp(p,d,16)!=0;
}
