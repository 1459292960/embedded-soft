/* @date: 2021-05-29 19:28:00
    读取数据按字符串格式读入，王博的想法
@功能:

@目的:

*/


#include <stdio.h>

int main(void){
    int N = 0;
    scanf("%d",&N);
    // printf("%d\n",N);
    char a[3] = {};
    char b[14] = {};
    getchar(); // 换行
    for(int i = 0; i < N; i++){
        scanf("%s",a);
        if(a[0] == 'A') b[1]++;
        else if(a[0] == 'J') b[11]++;
        else if(a[0] == 'Q') b[12]++;
        else if(a[0] == 'K') b[13]++;
        else if(a[0] == '1') b[10]++; // 对于10这个地方，待问王博是如何处理的
        else{
            b[a[0]-'0']++;
        }
        getchar();
    }
    // 统计1、2、3、4张牌的组数
    int ones = 0,twos = 0,threes = 0,fours = 0;
    for(int i = 1;i < 14;i++){
        if(i-1) printf(" ");
        printf("%d",b[i]);
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
    printf("\n");
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

    return 0;
}