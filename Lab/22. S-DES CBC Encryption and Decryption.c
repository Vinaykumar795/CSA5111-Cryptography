#include <stdio.h>
/* Simplified DES (S-DES): CBC mode, 8-bit blocks, 10-bit key */
static int perm(int x,int n,const int *t,int k){
    int r=0; for(int i=0;i<k;i++)r=(r<<1)|((x>>(n-t[i]))&1); return r;
}
static int rot5(int x,int s){return ((x<<s)|(x>>(5-s)))&31;}
static int round_f(int r,int key){
    const int ep[]={4,1,2,3,2,3,4,1},p4[]={2,4,3,1};
    const int s[2][4][4]={{{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}},{{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}}};
    int x=perm(r,4,ep,8)^key, a=x>>4, b=x&15;
    int v=s[0][((a&8)>>2)|(a&1)][(a>>1)&3]*4+s[1][((b&8)>>2)|(b&1)][(b>>1)&3];
    return perm(v,4,p4,4);
}
static int sdes(int x,int decrypt){
    const int p10[]={3,5,2,7,4,10,1,9,8,6},p8[]={6,3,7,4,8,5,10,9};
    const int ip[]={2,6,3,1,4,8,5,7},inv[]={4,1,3,5,7,2,8,6};
    int key=perm(509,10,p10,10),a=rot5(key>>5,1),b=rot5(key&31,1);
    int k1=perm(a*32+b,10,p8,8),k2=perm(rot5(a,2)*32+rot5(b,2),10,p8,8);
    x=perm(x,8,ip,8);
    int l=x>>4,r=x&15;
    l^=round_f(r,decrypt?k2:k1);
    r^=round_f(l,decrypt?k1:k2);
    return perm(r*16+l,8,inv,8);
}
int main(void){
    const int plaintext[]={0x01,0x23},iv=0xAA;
    int ciphertext[2],previous=iv;
    printf("Encrypted: ");
    for(int i=0;i<2;i++){
        previous=ciphertext[i]=sdes(plaintext[i]^previous,0);
        printf("%02X ",ciphertext[i]);
    }
    previous=iv;
    printf("\nDecrypted: ");
    for(int i=0;i<2;i++){
        printf("%02X ",sdes(ciphertext[i],1)^previous);
        previous=ciphertext[i];
    }
    puts("");
    return 0;
}
