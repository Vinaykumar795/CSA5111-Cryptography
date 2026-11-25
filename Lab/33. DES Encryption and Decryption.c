#include <stdio.h>
#include <string.h>
#include <openssl/des.h>
/* DES is obsolete; this is only a lab demonstration. */
int main(void){
    DES_cblock key="12345678",plaintext="SECURITY",ciphertext,recovered;
    DES_key_schedule schedule;
    DES_set_key_unchecked(&key,&schedule);
    DES_ecb_encrypt(&plaintext,&ciphertext,&schedule,DES_ENCRYPT);
    DES_ecb_encrypt(&ciphertext,&recovered,&schedule,DES_DECRYPT);
    printf("Ciphertext: ");
    for(int i=0;i<8;i++)printf("%02X ",ciphertext[i]);
    printf("\nRecovered: %.8s\n",recovered);
    return memcmp(plaintext,recovered,8)!=0;
}
