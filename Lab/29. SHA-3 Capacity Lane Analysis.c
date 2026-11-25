#include <stdio.h>
#include <stdint.h>
/* One theta step, not full SHA-3. A nonzero lane may cancel by XOR. */
int main(void){
    uint64_t state[25]={0},columns[5]={0},delta[5];
    for(int i=0;i<16;i++)state[i]=1;
    for(int i=0;i<25;i++)columns[i%5]^=state[i];
    for(int x=0;x<5;x++){
        uint64_t v=columns[(x+1)%5];
        delta[x]=columns[(x+4)%5]^((v<<1)|(v>>63));
    }
    for(int i=0;i<25;i++)state[i]^=delta[i%5];
    int active=0;
    for(int i=16;i<25;i++)active+=(state[i]!=0);
    printf("After one theta step: %d of 9 capacity lanes nonzero\n",active);
    puts("This sample cannot establish a universal number of rounds.");
    return 0;
}
