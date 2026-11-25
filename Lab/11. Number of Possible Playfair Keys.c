#include <stdio.h>
#include <math.h>

int main() {
    long double f=1;

    for(int i=1;i<=25;i++)
        f*=i;

    printf("Total keys: %.8Le\n",f);
    printf("Power of 2: %.3Lf\n",log2l(f));

    printf("Unique keys: %.8Le\n",f/25);
    printf("Power of 2: %.3Lf\n",log2l(f/25));

    return 0;
}
