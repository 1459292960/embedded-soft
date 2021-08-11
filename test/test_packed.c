/* @date: 2021-08-01 19:18:39
@功能:
    测试__attribute__((__packed__)) 取消字节对齐的用法
@目的:

*/


#include<stdio.h>
typedef struct{
    
    int b;
    char a;
    short c;
    char d;
    
}ST1;
// 正确用法
typedef struct{
    int b;
    char a;
    short c;
    char d;
}__attribute__((__packed__)) ST2;
// 会引起警告，起不到取消字节对齐的效果
// typedef __attribute__((__packed__)) struct{
//     char a;
//     int b;
// }ST3;
int main(void){
    printf("%ld\n",sizeof(short));
    printf("%ld\n",sizeof(ST1));
    printf("%ld\n",sizeof(ST2));
    // printf("%ld\n",sizeof(ST3));
    return 0;
}

/*@在VScode中的输出：
---------------------------------
8
5
---------------------------------
@总结：

*/
