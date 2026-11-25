#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* Ranked Caesar-shift candidates using approximate English letter frequencies. */
static double score(const char *s){
    const double f[]={8.2,1.5,2.8,4.3,12.7,2.2,2,6.1,7,0.15,0.77,4,2.4,6.7,7.5,1.9,0.095,6,6.3,9.1,2.8,0.98,2.4,0.15,2,0.074};
    int counts[26]={0},n=0;
    for(int i=0;s[i];i++)if(s[i]>='A'&&s[i]<='Z'){counts[s[i]-'A']++;n++;}
    double chi=0;
    if(!n)return 1e99;
    for(int i=0;i<26;i++){double expected=n*f[i]/100.0,d=counts[i]-expected;chi+=d*d/expected;}
    return chi;
}
int main(void){
    char text[500],plain[26][500];
    double scores[26];
    int n=10;
    printf("Ciphertext: ");if(!fgets(text,sizeof(text),stdin))return 1;
    printf("Number of results: ");if(scanf("%d",&n)!=1)return 1;
    if(n<0)n=0;if(n>26)n=26;
    for(int k=0;k<26;k++){
        int j=0;
        for(;text[j];j++)plain[k][j]=isalpha((unsigned char)text[j])?
            (char)((toupper((unsigned char)text[j])-'A'-k+26)%26+'A'):text[j];
        plain[k][j]=0;scores[k]=score(plain[k]);
    }
    for(int i=0;i<n;i++){
        int best=0;for(int j=1;j<26;j++)if(scores[j]<scores[best])best=j;
        printf("Shift %d: %s",best,plain[best]);scores[best]=1e99;
    }
    return 0;
}
