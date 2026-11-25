#include <stdio.h>

int main() {
    int pc2[]={
        14,17,11,24,1,5,
        3,28,15,6,21,10,
        23,19,12,4,26,8,
        16,7,27,20,13,2,
        41,52,31,37,47,55,
        30,40,51,45,33,48,
        44,49,39,56,34,53,
        46,42,50,36,29,32
    };

    printf("First 24 bits:\n");

    for(int i=0;i<48;i++) {
        printf("%d ",pc2[i]);

        if(i==23)
            printf("\nSecond 24 bits:\n");

        if((i<24)!=(pc2[i]<=28)) {
            printf("Error");
            return 1;
        }
    }

    printf("\nDisjoint halves verified.");

    return 0;
}
