#include <stdio.h>
#include<string.h>

int main(void){
    char a[4] = {'a','b','c','d'};
    char b[4] = {0};

    printf("%ld %ld\n",sizeof(a),sizeof(b)); // 64位的机器，地址用8个字节表示
    printf("%ld %ld\n",strlen(a),strlen(b));
    printf("%ld\n",sizeof(long));
    printf("%ld  %ld\n",sizeof(float),sizeof(double));
    return 0;
}