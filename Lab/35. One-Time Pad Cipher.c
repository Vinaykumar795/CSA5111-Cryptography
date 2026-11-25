#include <stdio.h>
int main(void){
    const char plaintext[]="HELLO";
    const int key[]={3,19,5,7,2};
    char encrypted[6]={0},decrypted[6]={0};
    for(int i=0;i<5;i++){
        encrypted[i]=(plaintext[i]-'A'+key[i])%26+'A';
        decrypted[i]=(encrypted[i]-'A'-key[i]+26)%26+'A';
    }
    printf("Plaintext: %s\nCiphertext: %s\nDecrypted: %s\n",plaintext,encrypted,decrypted);
    return 0;
}
