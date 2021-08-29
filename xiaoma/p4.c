/* @date: 2021-08-28 20:35:18
@功能:
    小马智行第四题，算出原序列的最大前缀序列Amax_origin和最小前缀序列Amin_origin，交换a[i]、a[j]之后，
    算出此时序列的最大前缀Amax_change和最小前缀Amin_change，判断改变之前和改变之后是否相等
@目的:

*/


#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define max(x,y) (x > y ? x:y) // 宏定义实现两者中间取最大
#define min(x,y) (x < y ? x:y) // 宏定义实现两者中间取最小
/*
函数功能： 求最大前缀数组
参数说明：
    a :原数组名
    max_last: 0～a[index-1]求得的最大前缀
    index:调换（i,j）对中的i
    len :生成最大前缀数组的长度
返回值： 所生成最大前缀数组的首地址
*/
int * max_arr(int * a,int max_last,int index, int len){
    int * p = (int *)malloc(sizeof(int)*len);
    p[0] = max(a[index],max_last);
    for(int i = 1; i < len; i++){
       p[i] = max(p[i-1],a[index+i]);
    }
    return p;
}
// 生成最小前缀数组，形参含义与max_arr()函数类似
int * min_arr(int * a, int min_last, int index, int len){
    int * p = (int * )malloc(sizeof(int)*len);
    p[0] = min(a[index],min_last);
    for(int i = 1; i < len; i++){
        p[i] = min(p[i-1],a[index+i]);
    }
    return p;
}
// 检查a数组从a[index]开始是否与数组b相同
bool  check_same(int * a,int * b,int index,int len){
    int i = 0;
    for(i = 0; i < len; i++){
        if(a[index+i] != b[i]) break;
    }
    if(i < len) return false;
    else return true;
}


int main(void){
    int n = 0;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d\n",&a[i]);
    }
    int ans = 0;
    int max_last = 0X80000000; // int类型最小的一个数
    int min_last = 0x7FFFFFFF; // int类型最大的一个数
    int * Amax_origin = max_arr(a,0X80000000,0,n);
    int * Amin_origin = min_arr(a,0x7FFFFFFF,0,n); 

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            // 调换a[j]和 a[i]
            int temp = a[i];
            a[i]  = a[j];
            a[j]  = temp;
            if(i > 0){
                max_last = Amax_origin[i-1];
                min_last = Amin_origin[i-1]; 
            }
            int * Amax_change = max_arr(a,max_last,i,n-i);
            int * Amin_change = min_arr(a,min_last,i,n-i);

            if(check_same(Amax_origin,Amax_change,i,n-i) && check_same(Amin_origin,Amin_change,i,n-i)){
                ans++;
                printf("%d %d\n",i,j); // 调试使用
            }


            // 释放堆中的数组
            free(Amax_change);
            free(Amin_change);
            // 复原数组a
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    }
    printf("%d\n",ans);   
    return 0;
}