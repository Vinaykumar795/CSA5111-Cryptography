#include <stdio.h>
/* Insecure variable-length CBC-MAC forgery demonstration. */
static int encrypt(int x){return (5*x+7)&255;}
int main(void){
    int X=25,T=encrypt(X),second=X^T,forged=encrypt(T^second);
    printf("MAC(X)=%d; MAC(X || (X XOR MAC(X)))=%d\n",T,forged);
    return T!=forged;
}
