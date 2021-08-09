/* @date: 2021-08-08 21:23:21
    王博新星笔试第二题，将数组中的元素重新排列，使输出的值最大，已字符串的形式输出
@功能:

@目的:

*/


#include <stdio.h>
#include<string.h>
#include <stdbool.h>
// 比较两个数那个应该放在放在前面，才会使得结果最大。
// 返回true,表示a应该放前面
// 返回false，表示b应该放前面
bool bigger(int a,int b){
    int factor_a[6] = {0},factor_b[6] = {0};
    int i = 0;
    for(i = 0; a/10 > 0;i++){
        factor_a[i]=a%10;
        a = a/10;
    }
    factor_a[i] = a%10;
    int j = 0;
    for(j = 0; b/10 > 0; j++){
        factor_b[j] = b%10;
        b = b/10;
    }
    factor_b[j] = b%10;


    int len_a = i; // 数组最大元素下标，存放着最高位
    int len_b = j;
    // for(int i =len_a; i >= 0 ;i--){
    //     printf("%d ",factor_a[i]);

    // }
    // printf("\n");
    // for(int i =len_b; i >= 0 ;i--){
    //     printf("%d ",factor_b[i]);

    // }
    // printf("\n");
        

    while(i >=0 && j >= 0){
        if(factor_a[i] > factor_b[j]) return true;
        else if(factor_a[i] < factor_b[j]) return false;
        else{
            i--;
            j--;
        }
            

    }
    if(j < 0){
        while(i >= 0){
            if(factor_a[len_a] < factor_a[i]) return true;
            else if(factor_a[len_a] > factor_a[i]) return false; // a应该放在数组后面一个
            else{
                len_a--;
                i--;
            }
        }
        


    }
    else{
        while(j >= 0){
        if(factor_b[len_b] < factor_b[j]) return false;
        else if(factor_b[len_b] > factor_b[j]) return true; // a应该放在数组后面一个
        else{
            len_b--;
            j--;
        }
    }
        
    }

}

// 主函数
int main(void){
    getchar();
    int num[100] = {0};
    int i = 0; 
    while(scanf("%d",&num[i++]) != EOF){
        getchar();
    }
    int len  = i - 1; // 数组的长度
    for(int i = 0;i < len-1; i++){
        for(int j = i+1; j < len; j++){
            if(bigger(num[i],num[j]))
                continue;
            else{
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    char src[10000] = {0} ;
    char temp_src[100] = {0};
    for(int i = 0; i < len;i++){

        sprintf(temp_src,"%d",num[i]); // 将数字转换为字符串
        strcat(src,temp_src);
    }
    printf("%s\n",src);
    return 0;
}