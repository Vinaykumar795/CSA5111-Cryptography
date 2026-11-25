#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* Monoalphabetic substitution: heuristic frequency-ranked candidates. */
int main(void){
    char ciphertext[500],decoded[26][500];
    const char rank[]="ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int freq[26]={0},order[26],n=10;
    printf("Enter ciphertext: ");if(!fgets(ciphertext,sizeof(ciphertext),stdin))return 1;
    printf("Number of candidates: ");if(scanf("%d",&n)!=1)return 1;
    if(n<0)n=0;if(n>26)n=26;
    for(int i=0;i<26;i++)order[i]=i;
    for(int i=0;ciphertext[i];i++)if(isalpha((unsigned char)ciphertext[i]))
        freq[toupper((unsigned char)ciphertext[i])-'A']++;
    for(int i=0;i<25;i++)for(int j=i+1;j<26;j++)if(freq[order[j]]>freq[order[i]]){
        int t=order[i];order[i]=order[j];order[j]=t;
    }
    for(int k=0;k<26;k++){
        char map[26];
        for(int j=0;j<26;j++)map[order[j]]=rank[j];
        if(k){char t=map[order[k]];map[order[k]]=map[order[k-1]];map[order[k-1]]=t;}
        int j=0;
        for(;ciphertext[j];j++)decoded[k][j]=isalpha((unsigned char)ciphertext[j])?
            map[toupper((unsigned char)ciphertext[j])-'A']:ciphertext[j];
        decoded[k][j]=0;
    }
    for(int k=0;k<n;k++)printf("Candidate %d: %s",k+1,decoded[k]);
    puts("Candidates are heuristics, not guaranteed correct decodings.");
    return 0;
}
