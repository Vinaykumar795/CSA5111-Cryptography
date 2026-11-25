#include <stdio.h>
static int extended_gcd(int a,int b,int *x,int *y){
    if(!b){*x=1;*y=0;return a;}
    int u,v,g=extended_gcd(b,a%b,&u,&v);
    *x=v;*y=u-(a/b)*v;return g;
}
int main(void){
    int n=3599,e=31,p=2,x,y;
    while(n%p)p++;
    int q=n/p,phi=(p-1)*(q-1);
    if(extended_gcd(e,phi,&x,&y)!=1){puts("No inverse");return 1;}
    int d=(x%phi+phi)%phi;
    printf("p=%d q=%d phi=%d private_key=(%d,%d)\n",p,q,phi,d,n);
    return 0;
}
