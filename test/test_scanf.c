/* @date: 2021-03-31 10:56:00
@功能:
 scanf %c前面加一个空格，可以跳过/忽略空格、换行、制表符等
@目的:

*/


#include "stdio.h"

int main(void){
    char str[10];
    int i;
    for(i = 0; i < 10;i++){
        scanf(" %c",&str[i]); // %c前面有一个空格
    }
    for(i = 0;i<10;i++){
        printf("%c",str[i]);
    }
}