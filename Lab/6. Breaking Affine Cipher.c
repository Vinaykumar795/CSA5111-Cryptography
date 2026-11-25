#include <stdio.h>

int gcd(int a,int b) {
    return b ? gcd(b,a%b) : a;
}

int main() {
    for(int a=0;a<26;a++) {
        for(int b=0;b<26;b++) {
            if(gcd(a,26)==1 &&
               (4*a+b)%26==1 &&
               (19*a+b)%26==20) {
                printf("a = %d\nb = %d\n",a,b);
            }
        }
    }

    return 0;
}
