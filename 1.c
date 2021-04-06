/* @date: 2021-04-01 09:57:26
@功能:
    统计球队比赛得分，并按分数从高到低排序；分数相同的，按字母顺序排序。分数为0的、参加了的
    队伍也要输出
@目的:

*/


#include <stdio.h>
#include <string.h>

typedef struct{
    char name;
    int score;
}QD;

int main(void){
    int i,j;
    int num_delimer = 0;
    int num[26] = {0};
    int team_attend[26] = {0}; // 记录参加了比赛的队伍
    
    char  str[20],str1[20];
    while(scanf("%s",str) != EOF){
        scanf("%s",str1);
        if(str1[0]>str1[2]){
            num[str[0]-'a']+=3; // 赢的队得3分
            num[str[2]-'a']+=0;  // 输的队不得分
        }
        else if(str1[0] == str1[2]){
            num[str[0]-'a']+=1;  // 平局，双方各得一分
            num[str[2]-'a']+=1; 
        }
        else{
            num[str[0]-'a']+=0; 
            num[str[2]-'a']+=3;            
        }
        team_attend[str[0]-'a'] = 1;
        team_attend[str[2]-'a'] = 1;

    }
    // 统计有多少只队伍参加了比赛
    for(i = 0;i < 26;i++){
        if(team_attend[i] != 0){
        num_delimer++;     
        }
    }

    QD qiudui[26]; // 定义结构体数组
    QD temp;
    for(i = 0;i < 26; i++){
        qiudui[i].name = 'a'+i;
        qiudui[i].score = num[i];

    }

    // printf("%d\n",num[0]);
    // printf("%d\n",num[1]);
    // 将最小的放在最后

    for(i = 0; i < 26; i++){
        for(j = 0; j<26-i-1;j++){
            if(qiudui[j].score<qiudui[j+1].score){
                temp = qiudui[j];
                qiudui[j] = qiudui[j+1];
                qiudui[j+1] = temp;
            }
        }
    }

// 输出分数不为0的队伍
    for(i = 0;i < 26;i++){
        if(qiudui[i].score != 0 ){

        printf("%c %d",qiudui[i].name,qiudui[i].score);
        team_attend[i]  = 0; // 输出后将该队参加比赛的标志清零
         if(num_delimer>1) 
            printf(",");
        num_delimer--;                  

        }
    }
    // 输出参加了比赛，但是分数为0的队伍
    int res = num_delimer; // 剩下分数为0的队伍数目
    for(i = 0;i < res; i++){
        for(int j= 0; j < 26 ; j++){
                    if(team_attend[j] && num[j] == 0){
                        printf("%c %d",j+'a',0);
                        if(num_delimer>1) 
                             printf(",");
                         num_delimer--;    
                    }
        }
    }
    return 0;
}