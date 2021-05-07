/*@date:2021-04-07
    陈世杰笔试第一题
@功能:
    4月7号阿里测试第一题，用上面键盘的符号代替数字进行计算并且表示
    以字符串的形式读入，更技高一筹，不用管两个字符串之间隔了几个空格
@目的:
    
*/


#include <stdio.h>
#include<math.h>
// 将符号转换为数字
int func1(char a){
    switch (a){
        case ')':
            return 0;
        case '!':
            return 1;
        case '@':
            return 2;
        case '#':
            return 3;
        case '$':
            return 4; 
        case '%':
            return 5;
        case '^':
            return 6;
        case '&':
            return 7;
        case '*':
            return 8;
        case '(':
            return 9;         
    }
}
// 将数字转换为字符
char func2(int a){
     switch (a){
        case 0:
            return ')';
        case 1:
            return '!';
        case 2:
            return '@';
        case 3:
            return '#';
        case 4:
            return '$'; 
        case 5:
            return '%';
        case 6:
            return '^';
        case 7:
            return '&';
        case 8:
            return '*';
        case 9:
            return '(';         
    }   

}
int ConvertStringToNum(char * a,int length){
    int sum = 0,label = 1,j = 0;
    int c[16]={0};
    // printf("%s\n%s\n",a,b);
    for(int i = 0; i< length; i++){
        if(a[i] == '-'){
            label = -1;
            continue;
        }
        // convert character to num
        c[j] = func1(a[i]);
        j++;

             
    }
    for(int k = 0; k < j; k++){
            sum += c[k]*pow(10,j-k-1);
    }


    return label*sum;

}


void NumToString(int sum){
    int label = 1;
    char b[17] = {};
    int k = 0;
    if(sum >= 0) label =1;
    else {
        label = -1;
        sum = (-1)*sum;

    }
    for( ;sum > 9;sum = sum/10){
        b[k] = func2(sum%10);
        k++;
        
    }
    b[k] = func2(sum);
    if(label == -1) printf("-");
    for(int n = k; n >= 0; n--){
        printf("%c",b[n]);

    }
    printf("\n");    


}

int main(void){

    int T;
    char a[17] = {};
    char b[17] = {};

    int i = 0,j = 0, k =0;
    int sum1 = 0,sum2 = 0,sum =0;
    int length1 = 0,length2 = 0; 

    scanf("%d",&T);
    getchar();

    int c[16];
    // scanf("%s%s",a,b);
    // printf("%s\n%s\n",a,b);
    // printf("%c\n",a[0]);
    // for(i = 0; i < 17; i++){
    //     if(a[i] == 0) break; 
    // }
    // for(int k = 0; k < i;k++){
    //     printf("%c",a[k]);
    // }
    // printf("\n");
    // printf("%d\n",func1(a));
    // printf("%d\n",a);
    for(int i = 0; i < T; i++){
            // 读完一个字符串
        scanf("%s%s",a,b);
        // calculate the first string's length
        for(length1 = 0; length1 < 17; length1++){
            if(a[length1] == 0) break;
        }  
        // calculate the second string's length
        for(length2 = 0; length2 < 17; length2++){
            if(b[length2] == 0) break;
        }

        sum1 = ConvertStringToNum(a,length1);
        sum2 = ConvertStringToNum(b,length2);

        // printf("%d\n%d\n",sum1,sum2);

        // 消空格
        // getchar();

        // sum2 = ConvertStringToNum();
        
        // // getchar();
        sum = sum1+sum2;
        NumToString(sum);
        sum = sum1-sum2;
        NumToString(sum);
        sum = sum2-sum1;
        NumToString(sum);
        // printf("%d\n",sum1+sum2);
        // scanf("%c",&b);
        // c = func1(a);
        // d = func1(b);
        // printf("%c\n",c+d);
        // c-d
        // printf("");



    }
    return 0;
}

/*在VScode中的输出：
-!!
##
-##
%%
-!!
!!      
总结：
    模块化编程，一点点实现功能，最后拼接成整体的程序。
*/
