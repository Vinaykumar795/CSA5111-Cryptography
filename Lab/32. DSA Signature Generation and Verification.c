#include <stdio.h>
/* Toy DSA parameters are for teaching only, not secure signatures. */
static int powmod(int a,int b,int m){
    int r=1;while(b--){r=r*a%m;}return r;
}
static int inverse(int a,int m){
    for(int i=1;i<m;i++)if(a*i%m==1)return i;
    return 0;
}
int main(void){
    int p=23,q=11,g=4,x=3,h=5,y=powmod(g,x,p);
    for(int k=1;k<q;k++){
        int r=powmod(g,k,p)%q,s=inverse(k,q)*(h+x*r)%q;
        if(!r||!s)continue;
        int w=inverse(s,q);
        int v=(powmod(g,h*w%q,p)*powmod(y,r*w%q,p)%p)%q;
        printf("k=%d signature=(%d,%d) verified=%s\n",k,r,s,(v==r)?"yes":"no");
        if(v!=r)return 1;
    }
    return 0;
}
