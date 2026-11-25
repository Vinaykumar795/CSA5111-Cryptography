#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
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

void decode(char *s,char *m,char *v) {
    int i;

    for(i=0;s[i];i++)
        v[i]=isalpha(s[i])?
        m[toupper(s[i])-'A']:s[i];

    v[i]='\0';
}

int main() {
    char s[500],m[26],v[500],best[10][500];
    double scores[10];
    int n=10;

    printf("Enter ciphertext: ");
    fgets(s,500,stdin);

    printf("Number of candidates: ");
    scanf("%d",&n);

    if(n>10) n=10;

    for(int i=0;i<10;i++)
        scores[i]=-1e99;

    srand(1);

    for(int r=0;r<40;r++) {
        for(int i=0;i<26;i++)
            m[i]='A'+i;

        for(int i=25;i>0;i--) {
            int j=rand()%(i+1);
            char t=m[i];
            m[i]=m[j];
            m[j]=t;
        }

        decode(s,m,v);
        double z=score(v);

        for(int k=0;k<5000;k++) {
            int i=rand()%26,j=rand()%26;

            char t=m[i];
            m[i]=m[j];
            m[j]=t;

            decode(s,m,v);
            double a=score(v);
            double temp=0.2+3.0*(5000-k)/5000.0;

            if(a>=z ||
               (double)rand()/RAND_MAX<exp((a-z)/temp))
                z=a;
            else {
                t=m[i];
                m[i]=m[j];
                m[j]=t;
            }
        }

        decode(s,m,v);

        int dup=0;

        for(int i=0;i<10;i++)
            if(scores[i]>-1e98 && !strcmp(best[i],v))
                dup=1;

        if(!dup) {
            for(int i=0;i<10;i++) {
                if(z>scores[i]) {
                    for(int j=9;j>i;j--) {
                        scores[j]=scores[j-1];

                        if(scores[j]>-1e98)
                            strcpy(best[j],best[j-1]);
                    }

                    scores[i]=z;
                    strcpy(best[i],v);
                    break;
                }
            }
        }
    }

    for(int i=0;i<n && scores[i]>-1e98;i++)
        printf("%d: %s\n",i+1,best[i]);

    return 0;
}
