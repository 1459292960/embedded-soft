#include <stdio.h>
/*
函数功能，将内存中存放的二进制的数据x转换对应的十进制数据返回

*/
short func(unsigned short x){
    short y = 0;
    short anticode = 0;
    y = x >> 15; // 取x的第一位
    anticode =  ~x; //按位取反
    if(y){
        return -(anticode+1); // 如果第一位是1，表示该数是一个负数，所有位取反加1得到的是该数的绝对值
    }
    else
        return anticode+1; // 否则，所有位取反加1得到的就是该数
}
int main(void){
    unsigned short x = 0xFFEC;
    printf("%d\n",func(x));
}


/*@在VScode中的输出：
---------------------------------
-20
---------------------------------
@总结：

*/
