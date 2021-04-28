/* @date: 2021-04-27 21:22:36
@功能:
    给定的两行数，第一行数为数组元素，第二行数为数组长度
    首先输出数组的最大值和最小值，然后将最大值和最小值用0代替，再将数组从小到大输出
@目的:
    注意输入scanf()的用法
*/


#include <stdio.h>
void  bubble_sort(int * a,int n){
    int temp = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;

            }
        }
    }

}
int main(void){
    int n = 0;
    int a[100]={0};
    int i = 0;
    while(1){

        if(scanf("%d",&n) == EOF) break; // 最后一次格式化输入失败时，并没有把数赋给n
        a[i++] = n;

    }
   // printf("%d\n",i);
   // printf("%d\n",n);
    // for(int j = 0; j < n;j++ ) printf("%d ",a[j]);
    bubble_sort(a,n);
    printf("%d %d\n",a[0],a[n-1]);
    a[0] = 0;
    a[n-1] = 0;
    bubble_sort(a,n);
    for(int i  = 0; i < n; i ++){
        i&&printf(" "); // 第一次循环不会输出空格，以后每次循环先输出空格，以此达到最后没有空格的目的
        printf("%d",a[i]);
    }


    return 0;
}