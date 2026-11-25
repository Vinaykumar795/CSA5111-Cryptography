#include <stdio.h>
#include <string.h>

int main() {
    char m[26];

    char c[] =
    "KXJEYUREBEZWEHEWRYTUHEYFS"
    "KREHEGOYFIWTTTUOLKSYCAJPO"
    "BOTEIZONTXBYBNTGONEYCUZWR"
    "GDSONSXBOUYWRHEBAAHYUSEDQ";

    printf("Enter 25-letter key matrix: ");
    scanf("%25s",m);

    if(strlen(m)!=25)
        return 1;

    printf("Decrypted: ");

    for(int i=0;c[i];i+=2) {
        char a=c[i],b=c[i+1];

        if(a=='J' && !strchr(m,'J')) a='I';
        if(b=='J' && !strchr(m,'J')) b='I';

        char *u=strchr(m,a);
        char *v=strchr(m,b);

        if(!u || !v)
            return 1;

        int x=u-m,y=v-m;
        int r1=x/5,c1=x%5;
        int r2=y/5,c2=y%5;

        if(r1==r2) {
            c1=(c1+4)%5;
            c2=(c2+4)%5;
        }
        else if(c1==c2) {
            r1=(r1+4)%5;
            r2=(r2+4)%5;
        }
        else {
            int t=c1;
            c1=c2;
            c2=t;
        }

        printf("%c%c",m[r1*5+c1],m[r2*5+c2]);
    }

    return 0;
}
