/* @date: 2021-06-10 22:11:16
    乐鑫笔试第一题，n=m*k,求出m+k最小值
@功能:

@目的:

*/


#include<stdio.h>

int main(void){
    int n,min,m,k;
    scanf("%d",&n);
    min = n+1;
    // m为除数
    for(m = 2;m*m <= n;m++){
        if(n%m == 0){
            k = n/m; // k为商
            if((m+k) < min){
                min = m+k;
            }
        }
    }
    printf("%d\n",min);

    return 0;
}