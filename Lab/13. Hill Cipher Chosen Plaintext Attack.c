#include <stdio.h>

int main() {
    int K[2][2]={{9,4},{5,7}};
    int P[2][2]={{1,0},{0,1}};
    int C[2][2]={0};

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                C[i][j]+=K[i][k]*P[k][j];

    printf("Chosen plaintext: BA and AB\n");
    printf("Recovered key matrix:\n");

    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++)
            printf("%d ",C[i][j]%26);

        printf("\n");
    }

    return 0;
}
