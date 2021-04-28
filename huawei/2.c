
/* @date: 2021-04-09 09:26:55
    华为实习生技术面，自己当场写的代码
@功能:
    求出数组的中心索引值，复杂度为O(n^2)
    外面一层循环复杂度为n，内部两个for循环分别为i和n-i
@目的:

*/


#include <stdio.h>
// 彭斌
int main(void){
    int num[] = {1,7,3,6,5,6};
    int length = sizeof(num)/sizeof(num[0]);
    // printf("%d\n",length);
    int sum_left = 0,sum_right = 0;
    int i;
    for( i = 1; i < length; i++){
        sum_left = 0;
        sum_right = 0;
        if(length == 1){
            printf("0\n");
            break;

        } 
        // 将左边的数计算出值
        for(int j = 0; j < i; j ++){
            sum_left += num[j];
        }
        // printf("sum_left = %d\n",sum_left);
        // right
        for(int k = i+1; k < length; k++){
            sum_right += num[k];
        }
        // printf("sum_right = %d\n",sum_right);
        if(sum_left == sum_right){
                printf("%d\n",i);
                break;
        } 
        

    }
    if(i == length) printf("-1\n");
    return 0;
}