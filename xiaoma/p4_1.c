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
    a :数组名
    max_last: a[0]～a[start-1]求得的最大前缀
    min_last: a[0]～a[start-1]求得的最小前缀
    start、end:分别对应i，j
返回值： 返回指针的指针，所生成最大和最小前缀数组的首地址
*/
// 将pArray 改为int ** 
int ** pre_arr(int * a,int max_last,int min_last,int start, int end){
    int len = end-start+1;
    int * p_max = (int *)malloc(sizeof(int)*len);
    int * p_min = (int *)malloc(sizeof(int)*len);

    p_max[0] = max(a[start],max_last);
    p_min[0] = min(a[start],min_last);
    for(int i = 1; i < len; i++){
       p_max[i] = max(p_max[i-1],a[start+i]);
       p_min[i] = min(p_min[i-1],a[start+i]);
    }
    int ** p = (int **)malloc(sizeof(int *)*2);
    p[0] = p_max;
    p[1] = p_min;
    return p;
}
// 检查a数组从a[index]开始是否与数组b相同
bool  check_same(int * a,int * b,int start,int end){
    int len = end - start+1;
    int i = 0;
    for(i = 0; i < len; i++){
        if(a[start+i] != b[i]) break;
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
    int ** pre_origin = pre_arr(a,0X80000000,0x7FFFFFFF,0,n);

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            // 调换a[j]和 a[i]
            int temp = a[i];
            a[i]  = a[j];
            a[j]  = temp;
            if(i > 0){
                max_last = pre_origin[0][i-1];
                min_last = pre_origin[1][i-1]; 
            }
            int ** pre_change = pre_arr(a,max_last,min_last,i,j);

            if(check_same(pre_origin[0],pre_change[0],i,j) && check_same(pre_origin[1],pre_change[1],i,j)){
                ans++;
                // printf("%d %d\n",i,j); // 调试使用
            }


            // 释放堆中的数组
            free(pre_change[0]);
            free(pre_change[1]);
            // 复原数组a
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    }
    printf("%d\n",ans);   
    return 0;
}