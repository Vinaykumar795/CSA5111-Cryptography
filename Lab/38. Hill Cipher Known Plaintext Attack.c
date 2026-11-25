#include <stdio.h>
static int mod(int x){return (x%26+26)%26;}
int main(void){
    const int P[2][2]={{1,2},{3,5}};
    const int C[2][2]={{21,12},{0,19}};
    int invP[2][2],K[2][2]={0};
    int det=mod(P[0][0]*P[1][1]-P[0][1]*P[1][0]),inv=0;
    for(int i=1;i<26;i++)if(det*i%26==1)inv=i;
    if(!inv){puts("Non-invertible known plaintext matrix");return 1;}
    invP[0][0]=mod(inv*P[1][1]);invP[0][1]=mod(-inv*P[0][1]);
    invP[1][0]=mod(-inv*P[1][0]);invP[1][1]=mod(inv*P[0][0]);
    for(int i=0;i<2;i++)for(int j=0;j<2;j++){
        for(int k=0;k<2;k++)K[i][j]+=C[i][k]*invP[k][j];
        K[i][j]=mod(K[i][j]);
    }
    printf("Recovered Hill key:\n%d %d\n%d %d\n",K[0][0],K[0][1],K[1][0],K[1][1]);
    return 0;
}
