/*@date:2021-04-28
    20210428宋迪笔试第一题
@功能:
    
@目的:
    
*/


#include <stdio.h>

int main(void){
    int M = 0,N = 0;
    scanf("%d%d",&M,&N);
    int a[M][N] ={0};
    int sum = 0;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            scanf("%d",&a[i][j]);
        }

    }
    // for(int i = 0; i < M; i++){
    //     for(int j = 0; j < N; j++){
    //         j&&printf(" ");
    //         printf("%d",a[i][j]);
    //     }
    //     printf("\n");

    // }  
    // int m = 0,n = 0;
    // if a[m+1][n]
    
    return 0;
}