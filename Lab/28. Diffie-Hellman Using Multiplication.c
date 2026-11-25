#include <stdio.h>
int main(void){
    int a=5,alice_secret=6,bob_secret=15;
    int alice_sent=a*alice_secret,bob_sent=a*bob_secret;
    int alice_key=alice_secret*bob_sent,bob_key=bob_secret*alice_sent;
    int eve_key=alice_sent*bob_sent/a;
    printf("Alice key=%d Bob key=%d Eve key=%d\n",alice_key,bob_key,eve_key);
    printf("Eve also recovers x=%d y=%d\n",alice_sent/a,bob_sent/a);
    puts("Ordinary multiplication is not a secure substitute for modular exponentiation.");
    return 0;
}
