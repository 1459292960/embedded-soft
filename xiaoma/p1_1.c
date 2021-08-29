/* @date: 2021-08-29 19:09:15
@功能:
    小马智行第一题，出试卷
    用的数学方法进行暴力列举方法
@目的:

*/



#include <stdio.h>
#include <stdlib.h>
#define max(x,y) (x > y ? x:y)
#define min(x,y) (x < y ? x:y)
int main(void){
    int T;
    scanf("%d",&T);
    int a[5] = {0};
    for(int i = 0; i < T; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d",&a[j]); // 注意这里是&a[j]，不是&a[i]
            // printf("a[%d] = %d\n",j,a[j]);
        }
        // printf("%d");
        int min_num =  0x7FFFFFFF;
        int ans = 0;
        for(int x = 0; x <= a[1]; x++){
            for(int y = 0; y <= a[3]; y++){
                int num_1 = a[0]+x, num_2 = a[1]-x+a[2]+a[3]-y, num_3 = y+a[4];
                int err1 = abs(num_1-num_2), err2 = abs(num_3-num_2);
                int err = max(err1,err2);
                if(err < min_num){
                    ans = min(min(num_1,num_2),num_3); // 更新答案
                    min_num = err; // 最小的不均匀性更新
                }

            }
        }
        // printf("%d\n",min(min(1,2),3));
        printf("%d\n",ans);
        
    }
    return 0;
}