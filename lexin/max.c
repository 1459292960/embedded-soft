/* @date: 2021-07-02 22:02:38
@功能:
    宏定义实现求最大值
@目的:

*/


#include <stdio.h>
#define MAX(a,b) (a>b?a:b)
// 宏定义中间不能有多余空格、空行
// (void)那一行的作用是，当a和b的数据类型不一样时，给出一个警告
#define MAX2(a,b) ({\
    typeof(a) x_ = a;\
    typeof(b) y_ = b;\
    (void)(&x_ == &y_);\
    (x_ > y_ ? x_:y_);\
})

int main(void){
    int a = 6;
    int b = 9;
    int e = 6;
    int f = 9;
    int c = MAX(a++,++b); // b进行了两次++b运算，
    int d = MAX2(e++,++f); // 这里进行了一次++f运算
    printf("%d\n",c);  
    printf("%d\n",d); 


    return 0;
}

/*@在VScode中的输出：
---------------------------------
11
10
---------------------------------
@总结：

*/
