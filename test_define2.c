/* @date: 2021-03-25 20:32:22
@功能:
    测试#define 作用，提供一个功能开关
@目的:

*/


#include "stdio.h"

#define hehe

int main(void)
{

    #ifdef hehe
    printf("bbbb\n");
    #else
    printf("aaaa\n");
    #endif
    return 0;
}

/*@在VScode中的输出：
---------------------------------
bbbb
---------------------------------
@总结：

*/
