#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* Heuristic frequency attack; candidates need not be valid plaintext. */
static double score(const char *s){
    const double freq[]={8.2,1.5,2.8,4.3,12.7,2.2,2.0,6.1,7.0,0.15,0.77,4,2.4,6.7,7.5,1.9,0.095,6,6.3,9.1,2.8,0.98,2.4,0.15,2.0,0.074};
    double val=0;
    for(int i=0;s[i];i++)if(s[i]>='A'&&s[i]<='Z')val+=freq[s[i]-'A'];
    return val;
}
int main(void){
    char text[500],candidates[26][500],map[26];
    const char rank[]="ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int counts[26]={0},order[26],n=10;
    double values[26];
    printf("Ciphertext: ");if(!fgets(text,sizeof(text),stdin))return 1;
    printf("Number of candidates: ");if(scanf("%d",&n)!=1)return 1;
    if(n<0)n=0;if(n>26)n=26;
    for(int i=0;i<26;i++)order[i]=i;
    for(int i=0;text[i];i++)if(isalpha((unsigned char)text[i]))counts[toupper((unsigned char)text[i])-'A']++;
    for(int i=0;i<25;i++)for(int j=i+1;j<26;j++)if(counts[order[j]]>counts[order[i]]){
        int t=order[i];order[i]=order[j];order[j]=t;
    }
    for(int k=0;k<26;k++){
        for(int i=0;i<26;i++)map[order[i]]=rank[i];
        if(k){char t=map[order[k]];map[order[k]]=map[order[k-1]];map[order[k-1]]=t;}
        int j=0;
        for(;text[j];j++)candidates[k][j]=isalpha((unsigned char)text[j])?map[toupper((unsigned char)text[j])-'A']:text[j];
        candidates[k][j]=0;values[k]=score(candidates[k]);
    }
    for(int i=0;i<n;i++){
        int best=0;for(int k=1;k<26;k++)if(values[k]>values[best])best=k;
        printf("Candidate %d: %s",i+1,candidates[best]);values[best]=-1e99;
    }
    return 0;
}
