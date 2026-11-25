#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double score(char *s) {
    double f[]={
        8.2,1.5,2.8,4.3,12.7,2.2,2,6.1,7,
        0.15,0.77,4,2.4,6.7,7.5,1.9,
        0.095,6,6.3,9.1,2.8,0.98,2.4,
        0.15,2,0.074
    };

    double z=0;

    for(int i=0;s[i];i++)
        if(isupper(s[i]))
            z+=log(f[s[i]-'A']);

    char *w[]={"THE","AND","ING","TH","HE","ER","IN","AN"};

    for(int j=0;j<8;j++)
        for(char *q=s;(q=strstr(q,w[j]));q++)
            z+=2;

    return z;
}

int main() {
    char s[500],v[26][500];
    double a[26];
    int n=10;

    printf("Enter ciphertext: ");
    fgets(s,500,stdin);

    printf("Number of results: ");
    scanf("%d",&n);

    for(int k=0;k<26;k++) {
        strcpy(v[k],s);

        for(int i=0;s[i];i++)
            if(isalpha(s[i]))
                v[k][i]=(toupper(s[i])-'A'-k+26)%26+'A';

        a[k]=score(v[k]);
    }

    for(int i=0;i<n && i<26;i++) {
        int b=0;

        for(int k=1;k<26;k++)
            if(a[k]>a[b])
                b=k;

        printf("Key %d: %s",b,v[b]);
        a[b]=-1e99;
    }

    return 0;
}
