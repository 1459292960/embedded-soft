/* @date: 2021-07-03 22:21:13
@功能:
    宏定义实现数字转字符串
@目的:

*/


#include <stdio.h>
#define RATE 115200
#define STR1(x) #x // #表示不要解析了，按字符串进行处理
#define STR2(x) STR1(x)




int main(void){
    printf("%s\n",STR2(RATE));
    return 0;
}