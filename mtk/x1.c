#include <stdio.h>
#include<string.h>

int main(void){
    printf("%d %d\n",strlen("\\test"),strlen("\x21"));
    return 0;
}