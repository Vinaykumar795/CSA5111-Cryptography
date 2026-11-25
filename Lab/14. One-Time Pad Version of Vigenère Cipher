#include <stdio.h>

int main() {
    char p[]="SENDMOREMONEY";
    char t[]="CASHNOTNEEDED";
    char c[14];

    int k[]={9,0,1,7,23,15,21,14,11,11,2,8,9};

    for(int i=0;i<13;i++)
        c[i]=(p[i]-'A'+k[i])%26+'A';

    c[13]='\0';

    printf("Ciphertext: %s\n",c);
    printf("New key: ");

    for(int i=0;i<13;i++)
        printf("%d ",(c[i]-t[i]+26)%26);

    return 0;
}
