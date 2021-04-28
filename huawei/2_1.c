/* @date: 2021-04-09 10:35:32
    华为实习生技术面代码题，萌哥提供思路，正确的写法
@功能:
    复杂度为O(n)的寻找中心索引值的方法。
@目的:

*/


#include <stdio.h>
#include<malloc.h>
int main(void){
    int len;
    int sum_right =0 ,sum_left = 0,j;
    printf("请输入数组的长度len = ");
    scanf("%d",&len);
    int * pArr = (int *)malloc(sizeof(int)*len);
    int * pSN = (int *)malloc(sizeof(int)*len);
    printf("请输入数组元素：\n");
    for(int i = 0; i < len; i++){
        scanf("%d",&pArr[i]);
    }
    // for(int i = 0; i < len; i++){
    //     printf("%d\n",pArr[i]);
    // }
    // 求出前n项的和，分别放入前n项和数组内
    if(len == 1){
        printf("0\n");
        return 0 ;

    } 
    // 求出前n项和，并放在新的数组里
    pSN[0] = pArr[0];
    for(int i = 1; i < len; i++){

        pSN[i] = pSN[i-1]+pArr[i];
    }
    // for(int i = 0; i < len; i++){
    //     printf("%d ",pSN[i]);
    // }    
    for(j = 1; j < len; j++){
        sum_left = pSN[j-1];
        // printf("sum_left =%d\n",sum_left);
        sum_right = pSN[len-1]-pSN[j];
        // printf("sum_ right = %d\n",sum_right);
        if(sum_left == sum_right){
            printf("%d\n",j);
            break;
        }

    }
    if(j == len) printf("-1\n");
    // 释放动态分配的内存空间，防止内存泄漏
    free(pArr);
    free(pSN);
    return 0;
}