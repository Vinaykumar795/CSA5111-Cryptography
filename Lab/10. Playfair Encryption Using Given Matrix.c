#include <stdio.h>
#include <string.h>

int main() {
    char m[]="MFHIKUNOPQZVWXYELARGDSTBC";

    char p[]=
    "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";

    printf("Encrypted: ");

    for(int i=0;p[i];) {
        char a=p[i++],b='X';

        if(p[i] && p[i]!=a)
            b=p[i++];

        int x=strchr(m,a)-m;
        int y=strchr(m,b)-m;

        int r1=x/5,c1=x%5;
        int r2=y/5,c2=y%5;

        if(r1==r2) {
            c1=(c1+1)%5;
            c2=(c2+1)%5;
        }
        else if(c1==c2) {
            r1=(r1+1)%5;
            r2=(r2+1)%5;
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
