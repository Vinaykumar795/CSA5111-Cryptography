#include <stdio.h>
static int mod(int a,int m){return (a%m+m)%m;}
static int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(void){
    const int a=5,b=8;
    char text[]="AFFINECIPHER";
    int inverse=0;
    for(int i=1;i<26;i++)if((a*i)%26==1)inverse=i;
    if(!inverse)return 1;
    printf("Plaintext: %s\n",text);
    for(int i=0;text[i];i++)text[i]=mod(a*(text[i]-'A')+b,26)+'A';
    printf("Encrypted: %s\n",text);
    for(int i=0;text[i];i++)text[i]=mod(inverse*(text[i]-'A'-b),26)+'A';
    printf("Decrypted: %s\nValid a: ",text);
    for(int i=0;i<26;i++)if(gcd(i,26)==1)printf("%d ",i);
    puts("\nb can be any integer modulo 26.");
    return 0;
}
