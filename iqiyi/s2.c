/* @date: 2021-08-01 16:57:17
    宋迪爱奇艺第2题，窗口滑动，计算每个窗口的平均值，输出幅度变化最大的一个百分比p
@功能:

@目的:

*/


#include<stdio.h>
#include<math.h> // 使用fabs函数
#include <stdlib.h>

int main(void){
    int a[1000];
    float p = 0,p_max = 0,ava = 0,pre = 0;
    float k,sum = 0;
    int i = 0,len = 0;
    while(scanf("%d",&a[i++]) != EOF){
        getchar(); // 吃掉两个数字之间的分割符，比如逗号，冒号
    }
    len = i -2; // 数组有效长度
    k = a[len]; // 窗口大小
    for(int j = 0; j < (len-k+1); j++){
        for(int n = 0; n < k; n++){
            sum+=a[j+n];
        }
        ava = sum/k; // 计算每个窗口数组的平均值
        sum = 0;
        if(j == 0) pre = ava;
        else{
            p = fabs((ava - pre)/pre);
            // printf("p = %f\n",p);
            if(p > p_max) p_max = p;
            pre = ava;
        }
         
        

    }
    // .2f表示输出两位小数
    printf("%.2f%%",p_max*100); // %%才能在输出中输出一个%

    return 0;
}