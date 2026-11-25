#include <stdio.h>
#include <openssl/aes.h>
/* CMAC subkeys for AES-128 (OpenSSL development package required). */
static void dbl(const unsigned char *in,unsigned char *out,int n){
    unsigned int carry=0;
    for(int i=n-1;i>=0;i--){
        out[i]=(unsigned char)((in[i]<<1)|carry);
        carry=in[i]>>7;
    }
    if(carry)out[n-1]^=(n==16)?0x87:0x1B;
}
int main(void){
    unsigned char zero[16]={0},L[16],K1[16],K2[16];
    AES_KEY key;
    if(AES_set_encrypt_key(zero,128,&key)!=0)return 1;
    AES_encrypt(zero,L,&key);
    dbl(L,K1,16);dbl(K1,K2,16);
    printf("K1: ");for(int i=0;i<16;i++)printf("%02X",K1[i]);
    printf("\nK2: ");for(int i=0;i<16;i++)printf("%02X",K2[i]);
    puts("\nReduction constants: 64-bit=0x1B, 128-bit=0x87");
    return 0;
}
