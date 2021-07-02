/* @date: 2021-06-18 22:15:24
    数组首元素的地址 与 数组首地址
@功能:

@目的:

*/


#include<stdio.h>

int main(void){
    int a[5] = {1,2,3,4,5};
    int * ptr = (int *)(&a+1);
    printf("数组首元素的首地址a = %p\n",a);
    printf("整个数组的首地址&a = %p\n",&a);
    printf("&a+1 = %p\n",(&a+1));
    printf("ptr = %p\n",ptr-1);
    return 0;
}