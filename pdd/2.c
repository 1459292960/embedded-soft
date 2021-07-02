/* @date: 2021-05-29 19:20:32
    宋迪PDD实习生笔试第二题，打扑克出牌次数最少。
@功能:
    
@目的:

*/


#include <stdio.h>
void CalNum(char a,char * b){
    switch (a){
        case 'A':
            b[0]++;
            return ;
        case '2':
            b[1]++;
            return ;
        case '3':
            b[2]++;
            return ;
        case '4':
            b[3]++;
            return ;
        case '5':
            b[4]++;
            return ;
        case '6':
            b[5]++;
            return ;
        case '7':
            b[6]++;
            return ;
        case '8':
            b[7]++;
            return ;
        case '9':
            b[8]++;
            return ; 
        case 'J':
            b[10]++;
            return ;
        case 'Q':
            b[11]++;
            return ;
        case 'K':
            b[12]++;
            return ;                                          
    }
}
int main(void){
    int N = 0;
    scanf("%d",&N);
    printf("%d\n",N);
    char a;
    char b[13] = {};
    int c[4] = {};
    getchar(); // 换行
    for(int i = 0; i < N; i++){
        scanf("%c",&a);
        if(a == '1'){
            b[9]++;
            getchar();
        }
        else{
            CalNum(a,b);
        }
        getchar();
    }
    // 统计1、2、3、4张牌的组数
    int ones = 0,twos = 0,threes = 0,fours = 0;
    for(int i = 0;i < 13;i++){
        // i && printf(" ");
        // printf("%d",b[i]);
        if(b[i] == 1) ones++;
        else if (b[i] == 2){
           twos++;
        }
        else if(b[i] == 3){
            threes++;

        }
        else if(b[i] == 4){
            fours++;
        }
        else;
        
    }
    int three = threes; // 打三张一起出去的次数
    while(threes > 0 && ones > 0){
        threes--;
        ones--;
    }
    while(threes > 1 && twos > 0){
        threes -= 2;
        twos--;
    }
    // 不管三带的是3个，还是4个的
    while(threes > 3){
        threes -= 4;
        three--;
    }
    printf("%d\n",ones+twos+three+fours);
    // int spe_num =0;
    // int num = 0;
    // if(c[2] <= c[0]){
    //     num = c[3]+c[2]+c[1]+c[0]-c[2]; // 全部三带1
    // }
    // else if((c[2]-c[0])<=2*c[1]){
    //     num = c[0]; // 三带1需要的次数
    //     c[2] = c[2] -c[0]; // 剩余三张牌的组数
    //     num = num+c[3]+c[2]+c[1]-c[2]/2;
    // }
    // // 3代3
    // else if(spe_num = c[2]-c[1]*2-c[0],(c[2]-c[1]*2-c[0]) <= 4*c[] ){

    // }
    // // if(c[0] == 0){
    // //     num = c[3]+c[2]+c[1];
    // // }
    // // else if(c[2] >= c[0]){
    // //     num = c[3]+c[2]+c[1];
    // // }
    // // else{
    // //     num = c[3]+c[1]+c[0];
    // // }
    // printf("%d\n",num);
    return 0;
}