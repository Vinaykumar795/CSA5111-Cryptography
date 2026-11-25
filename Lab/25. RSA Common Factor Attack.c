#include <stdio.h>
static int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(void){
    int n=3233,c=61; /* Toy RSA example: gcd(61,3233)=61 */
    int p=gcd(c,n);
    if(p>1&&p<n)
        printf("Factor p=%d, q=%d\n",p,n/p);
    else
        puts("No useful factor found");
    return 0;
}
