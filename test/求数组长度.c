/* @date: 2021-03-18 11:35:21
@功能:
用宏求数组元素个数
@目的:

*/


#include <stdio.h>
// int table[10]={1,2,3};
#define COUNT(table) (sizeof(table)/sizeof(table[0]))
int main()
{
    int a[5];
    printf("数组总长%ld,单个数组元素长度%ld,数组长度为%ld\n",sizeof(a),sizeof(a[0]),COUNT(a));
    return 0;
}

/*@在VScode中的输出：
---------------------------------
数组总长20,单个数组元素长度4,数组长度为5
---------------------------------
@总结：
sizeof()结果类型为long unsigned int ,用%ld输出
*/
