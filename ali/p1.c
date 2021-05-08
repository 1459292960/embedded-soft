/* @date: 2021-05-08 21:02:17
    4月30日阿里笔试第一题
@功能:

@目的:

*/


#include<stdio.h>
#include <math.h>
#include <stdlib.h>

// 比较函数，用在qsort函数中，用于从小到大排序
// 返回（1）负数：qsort将a放在b前面 （2）零：a和b的顺序不确定（3）正数：a放在b的后面返回
int cmp(const void * a, const void * b){
    return (*(int *)a - *(int *)b);
}
int main(void){
    int n;
    scanf("%d",&n);
    int a[2*n]; // 存储每个乘客的体重
    int b[n-1]; // 存储双人船两个人的体重
    int c[4] = {0};
    int res = 0;
    int max_num = 0;
    for(int i = 0; i < 2*n; i++){
        scanf("%d",&a[i]);
    }
    // for(int i = 0; i < 2*n; i++){
    //     printf("%d",a[i]);
    // }
    // printf("\n");
    if(n == 1){
        printf("%d\n",abs(a[1]-a[0]));
        return 0;
    }
    qsort(a,2*n,sizeof(a[0]),cmp);
    // printf("排序之后：\n");
    // for(int i = 0; i < 2*n; i++){
    //     printf("%d ",a[i]);
    // }
    // printf("\n");
    for(int i = 0 ; i < n-1; i++ ){
        b[i] = a[i]+a[2*(n-1)-1-i];
    }

    qsort(b,n-1,sizeof(b[0]),cmp);
    // printf("b 排序之后：\n");
    //  for(int i = 0; i < n -1 ; i++){
    //     printf("%d ",b[i]);
    // }
    // printf("\n"); 
    // 四种情况
    c[0]= b[n-2]-a[2*n-2]; // 双人船最重的 - 单人船最轻的     
    c[1] = a[2*n-1]-b[0]; // 单人船最重的 - 双人船最轻的
    c[2] = a[2*n-1]-a[2*n-2]; // 单人船最重的 - 单人船最轻的
    c[3] = b[n-2] - b[0]; // 双人船最重的 - 双人船最轻的
    qsort(c,4,sizeof(c[0]),cmp);
    printf("%d\n",c[3]);

    return 0;
}