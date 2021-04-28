#include "string.h"
#include "stdio.h"

int main(void){
    char str1[10] = "TsinghuaOK"; // 字符数组
    puts(str1);
    char str2[10] = {"Computer"};
    puts(str2);
    strcpy(str1,str2);
    printf("%s\n",str1);
    return 0;
}