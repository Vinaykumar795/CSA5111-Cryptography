#include <stdio.h>
/* Demonstration with small RSA numbers: leaked d compromises the modulus. */
int main(void){
    int n=3233,e=17,d=2753;
    int multiple=e*d-1;
    printf("Leaked d=%d, e*d-1=%d\n",d,multiple);
    for(int p=2;p*p<=n;p++)if(n%p==0){
        int q=n/p,phi=(p-1)*(q-1);
        if(multiple%phi==0)
            printf("Recovered toy factors: p=%d q=%d\n",p,q);
    }
    puts("Generating new (e,d) on the same modulus is unsafe: replace p, q and n.");
    return 0;
}
