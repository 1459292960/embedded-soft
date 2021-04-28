#include <stdio.h>
#include<string.h>
<<<<<<< HEAD
// 宏定义函数，用异或实现两个数互换值，宏定义相当于在文中使用的位置将swap替换成{}中的代码，所以不用传递地址
//  \ 每行后面不能呢个加空格或者注释，否则都会报错
=======
// 宏定义函数，用 异或 实现两个数互换值，宏定义相当于在文中使用的位置将swap替换成{}中的代码，所以不用传递地址
// 宏定义的 \ 每行后面不能加空格或者注释，否则都会报错
>>>>>>> 41f62c5eba0106f4cb5112aecbf912682ae8e593
#define swap(a,b){\
    a ^= b;\
    b ^= a;\
    a ^= b;\
}
// 冒泡法排序，把小的放在后面
void bubble_sort(int * num,int n){
    for(int i = 1;i < n; i++){
        for(int j = 0;j < n - i;j++){
            if(num[j] >= num[j+1]) continue;
            swap(num[j],num[j+1]);
        }
    }
    return;
}

int main(void){
    char s[100] = {0}; // 数组初始化清零
    int team[30]= {0};
    int team_label[30] = {0};
    /* ^ 取反
        [^\n]表示除换行符\n，其它字符都可以存入字符串s中,那么每次循环，读入一行字符串
        当读到文件末尾时，返回-1，补码为1111 1111，那么逐位（～）取反为0000 0000
    */
    while(~scanf("%[^\n]s",s)){
<<<<<<< HEAD
        char team1,team2;
=======
        char team1,team2; // 存储两个队伍名称
>>>>>>> 41f62c5eba0106f4cb5112aecbf912682ae8e593
        int score1,score2;
        // printf("%s",s);
   
        char * p = strstr(s,"-"); // 在字符串中搜索子字符串，返回第一次出现字符串 "-"的位置
        team1 = *(p-1); // 队伍名
        team2 = *(p+1);
        p  = strstr(s,":");
<<<<<<< HEAD
        score1 = *(p-1) - '0'; // 分数
        score2 = *(p+1) - '0';
        if(score1 >score2){
=======
        score1 = *(p-1) - '0'; // 分数，转化为实际的数字相比
        score2 = *(p+1) - '0';
        if(score1 > score2){
>>>>>>> 41f62c5eba0106f4cb5112aecbf912682ae8e593
            team[team1-'a']+=3;
            team[team2-'a']+=0;
        }
        else if(score1 == score2){
            
            team[team1-'a']+=1;
            team[team2-'a']+=1;
        }
        else{

            team[team1-'a']+=0;
            team[team2-'a']+=3;
        }
        team_label[team1-'a'] = 1; // 表示该队伍参加了比赛
        team_label[team2-'a'] = 1;
        // printf("%c-%c  %d:%d\n",team1,team2,team[team1-'a'],team[team2-'a']);
        getchar(); // 读取并丢弃换行符
        
    }
    int team_new[30]  = {0};
    // 旧的team数组作为球队编号识别用，新的team_new用作分数排序
    for(int i = 0;i < 26 ; i++){
        team_new[i] = team[i];
        // printf("%c:%d\n",i+'a',team[i]);

    }
    bubble_sort(team_new,26);
    int num = 0;
    // 统计总共有几个球队参赛,数量可以用作输出分割符的个数
    for(int i = 0;i < 26;i++){
        if(team_label[i] != 0 ) num++;
    }
    // printf("%d\n",num);
    // 输出得分不为0的队伍
    for(int i = 0;i < 26; i++){
        if(team_new[i] == 0) break;
        char teamname;
        int score;
        score = team_new[i];
        // 循环找到新排序的team_new中得分对应原来排序中team得分的哪一个
        for(int j = 0;j < 26; j++){
            if(team_new[i] == team[j] && team_label[j]){
                teamname = j + 'a';
                team_label[j]  = 0;
                break;
            }
        }
        printf("%c %d",teamname,score);
        num>1 && printf(",");
        num--;
    }
    // 输出参加比赛，但是得分为0的队伍，可能有多个
    // 在原来的数组中顺序寻找就可以，因为本来的数组就是按a~z顺序顺序存放分数的
    if(num){
        for(int i = 0; i < 26; i++){
            if(team[i] == 0 && team_label[i]){
                printf("%c %d",i+'a',0);
                num>1 && printf(",");
                num--;
            }
        }
    }

    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 41f62c5eba0106f4cb5112aecbf912682ae8e593
