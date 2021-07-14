/* @date: 2021-07-04 09:40:22
    陈世杰笔试题，递归 找钱问题
    <https://blog.csdn.net/qq_43361209/article/details/104238607>
    考虑最后一个人是五毛还是一元
@功能:

@目的:

*/


#include <stdio.h>

int text(int m, int n){
    if(m < n) return 0; // 五毛的人数 少于 一元的，无论如何都不能完成，情况为0

    else if( m == 1) return 1; // m>= n，那么n<=1，此时只有一种情况，拿五毛的站在前面先买票
    else if( n == 0) return 1; // n = 0 拿一元的人数为0，那么只有一种排队购票顺序

    // text(m-1,n) 最后一个人是五毛
    // text(m,n-1) 最后一个人是一元
    else return text(m-1,n)+text(m,n-1);

}
int main(void){
    int a = text(3,2);
    printf("%d\n",a);
    return 0;
}