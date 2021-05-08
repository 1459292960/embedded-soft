/* @date: 2021-05-08 20:47:37  
    宋迪趋势科技笔试编程第一题
@功能:

@目的:

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>

int value_real(char * a,int len){
    int sum = 0;
    int temp = 0 ;
    for(int i = 0; i < len; i++){
        temp = a[i]-'0';
        sum+=temp*pow(10,len-i-1);

    }
    return sum;
}
int main(void){
    char * a;
    scanf("%s",a);
    int x;
    int k;
    scanf("%d",&x);
    int len = strlen(a);
    // printf("len=%d\n",len);
    if(x == len) return 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < len-1;j++){
            if(a[j] > a[j+1]){
                
                for( k =j;k <len-1;k++){
                    a[k] = a[k+1];
                }
                a[k] ='\0';
                len = strlen(a);
                break;
            } 
        }
    }
    printf("%d\n",value_real(a,len));
    // printf("%c\n",a[0]);
    // printf("%s\n",a);
    // printf("%d\n",x);
    return 0;   
}