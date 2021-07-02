#include<stdio.h>
// 内联关键词inline要与函数定义用在一起才起作用
// 加上static修饰，不仅该函数对其他文件不可见，而且只会开辟一块空间，节省内存开销，到程序结束时才会释放掉
static inline char * dbtest(int a){
    return (a%2 > 0 ? "奇":"偶");
}
int main(void){
    for(int i = 0;i < 10; i++){
        printf("%d  %s\n",i,dbtest(i));
    }
    return 0;
}