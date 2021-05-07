/* @date: 2021-05-07 20:05:20
    李圣阿里笔试第一题，王博的思路,直接把数组b中每个数值需要操作的次数计算出来
@功能:
    
@目的:

*/


#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a,const void * b){
    return (*(int *)a - *(int *)b);
}
int main(void){
    int n,m;
    int num = 0;
 
    scanf("%d%d",&n,&m);
    int a[n]; // 注意定义数组的位置
    int b[m];

    for(int i =0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i  < m; i++){
        scanf("%d",&b[i]);
    }


    // printf("%d %d\n",n,m);
    // for(int i = 0; i  < m; i++){
    //     i && printf(" ");
    //     printf("%d",a[i]);
    // } 
    // printf("\n");
    // for(int i = 0; i  < m; i++){
    //     i && printf(" ");
    //     printf("%d",b[i]);
    // }
    // printf("\n");
    qsort(a,n,sizeof(a[0]),cmp);
    qsort(b,m,sizeof(b[0]),cmp);
    for(int i = 0; i < m; i++){
        if (a[n-1] > b[i]) num  += (a[n-1]-b[0]);
        else break;
    }
    // while(a[n-1] > b[0]){
    //     b[0]++;
    //     qsort(b,m,sizeof(b[0]),cmp);
    //     num++;

    // }
    printf("%d\n",num);
    return 0;
}