#include <stdio.h>
static long long modpow(long long a,int e,int n){
    long long r=1;
    while(e){if(e&1)r=r*a%n;a=a*a%n;e>>=1;}
    return r;
}
int main(void){
    const int n=3233,e=17;
    int ciphertext=(int)modpow(7,e,n); /* H encoded as 7 */
    printf("Ciphertext=%d\n",ciphertext);
    for(int p=0;p<26;p++){
        if(modpow(p,e,n)==ciphertext)
            printf("Dictionary attack recovered %c\n",'A'+p);
    }
    return 0;
}
