#include <stdio.h>

int main(void){
    printf("%ld\n",sizeof(char *)); // 64位的机器，地址用8个字节表示

    return 0;
}