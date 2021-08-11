/* @date: 2021-07-15 10:24:37
@功能:
    测试数组指针
@目的:

*/



#include <stdio.h>

int main(void){
    char a[5] = {'A','B','C','D'};
    char(*p1)[3] = &a;
    char(*p2)[3] = a;
    char(*p3)[10] = &a;
    char(*p4)[10] = a;
    printf("%s\n",*(p1+1));
    printf("%s\n",*(p2+1));   
    printf("%s\n",*(p3+1));
    printf("%s\n",*(p4+1));
    return 0;
}

/*@在VScode中的输出：
---------------------------------
D
D
�[`����U
�[`����U
---------------------------------
@总结：

*/
