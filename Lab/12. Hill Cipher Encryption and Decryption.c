#include <stdio.h>
#include <string.h>

int mod(int x) {
    return (x%26+26)%26;
}

int main() {
    char p[100]=
    "MEETMEATTHEUSUALPLACEATTENRATHERTHANEIGHTOCLOCK";

    char c[100],d[100];
    int n=strlen(p);

    if(n%2)
        p[n++]='X';

    p[n]='\0';

    for(int i=0;i<n;i+=2) {
        int x=p[i]-'A';
        int y=p[i+1]-'A';

        c[i]=mod(9*x+4*y)+'A';
        c[i+1]=mod(5*x+7*y)+'A';
    }

    c[n]='\0';

    for(int i=0;i<n;i+=2) {
        int x=c[i]-'A';
        int y=c[i+1]-'A';

        d[i]=mod(5*x+12*y)+'A';
        d[i+1]=mod(15*x+25*y)+'A';
    }

    d[n]='\0';

    printf("Plaintext: %s\n",p);
    printf("Encrypted: %s\n",c);
    printf("Decrypted: %s\n",d);

    return 0;
}
