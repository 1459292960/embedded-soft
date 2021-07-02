/* @date: 2021-05-29 19:18:48
    宋迪拼多多实习笔试 2021.5.27
@功能:
    追加字符串
@目的:

*/


#include<stdio.h>
#include<string.h>

int main(void){
    char a[500]={};
    int num = 0;
    // while(1){

    // }
    int i = 0;
    while(scanf("%s",a)!=EOF){
        num++;
        int len = strlen(a);
        if(a[0] == 'a' || a[0] == 'e'||a[0] == 'i'||a[0] == 'o'||a[0] == 'u'||\
        a[0] == 'A'||a[0] == 'E'||a[0]=='I'||a[0] == 'O'||a[0]=='U'){
  
        }
        else{
            char temp = a[0];
            for( i = 0; i < len-1; i++){
                a[i] = a[i+1];
            }
            a[i] = temp;
            a[len] = '\0';
        }
        strcat(a,"pdd");
        for(int j = 0; j < num;j++){
            strcat(a,"a");
        }
        if(num-1) printf(" ");
        printf("%s",a);
    }
    printf("\n");

    return 0;
}