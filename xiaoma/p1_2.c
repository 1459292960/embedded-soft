/* @date: 2021-08-29 21:00:35
@功能:
    小马智行第一题，二分➕答案
    难点在于每个答案的逻辑判断
@目的:

*/


#include <stdio.h>
#include <stdbool.h>
#define max(x,y) (x > y ? x:y)
#define min(x,y) (x < y ? x:y)
// 二分+答案
int mid_ans(int * b, int len,int min_num,int max_num){
    while(min_num < max_num){
        int mid = (min_num + max_num)/2;
        int num_1 = mid, num_2 = mid, num_3 = mid;
        int a[len];
        // 每次都使用备份数组进行操作
        for(int i = 0; i < len; i++){
            a[i] = b[i];
        }
        
        // bool flag1 = false, flag2 = false, flag3 = false;
        // 如果num_1大于第一类题的数目
        if(num_1 > a[0]){
            num_1 -= a[0];
            // 如果小于第二类题的数组
            if(num_1 <= a[1]){
                a[1] -= num_1;
            }
            // 否则说明num太高无法凑成这么多套试卷
            else{
                max_num = mid;
                continue;
            }
        }
        // 
        if(num_3 > a[4]){
            num_3 -= a[4];
            if(num_3 <= a[3]){
                a[3] -= num_3;
                // return mid; // 返回答案
            }
            else{
                max_num = mid;
                continue;
            }
        }

        // 判断剩下的 第二类和第三类和第四类 能否满足 题目套数 的要求
        if(num_2 > (a[1]+a[2]+a[3])){
            max_num = mid;
        
        }
        // mid小了，能够满足，看看是否能有更大的
        else{
            
            if( min_num != mid) min_num = mid;
            // 当 min_num 与 mid 相同时，说明min_num与max_num仅相差一个数，那么直接返回mid
            // 至于不是返回max_num，是因为当上一次是max_num向min_num靠近，
            // 此时的max_num是上一次的mid,不满足题目要求，才会变成此时的max_num；
            // 当上一次是min_num向max_num靠近时，此时的min_num与mid相同，
            // 例如min_num =3,max_num =4,mid = 3，若min_num = 3 再次进行计算
            // 则会陷入死循环，并且此次midmanzu条件，则直接返回mid
            else return mid;
        }

    }
    return min_num;
}

int main(void){
    int T;
    // printf("%d\n",1/2);
    scanf("%d",&T);
    int a[5] = {0};
    for(int i = 0; i < T; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d",&a[j]); // 注意这里是&a[j]，不是&a[i]
        }
        int min_num = min(min(a[0],a[2]),a[4]);
        int max_num = a[1]+a[2]+a[3];
        int ans = mid_ans(a,5,min_num,max_num);
        printf("%d\n",ans);


    }
    return 0;
}