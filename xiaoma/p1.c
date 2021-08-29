/* @date: 2021-08-29 18:41:56
@功能:
    小马智行第一题，深搜没有搜出来
@目的:

*/


#include <stdio.h>
int problem1 = 0,problem2 = 0, problem3  = 0;

int dfs(int * a,int index){
    if(a[0] == 0 && a[1] == 0) return 0;
    else if(a[3] == 0 && a[4] == 0) return 0;
    else{
        for(int i = 1; i < 4;i++){
            for(int j = index; j <= index+i; j++){

                if(j<2 && (a[j] != 0)){
                    a[j]--;
                    problem1 = 1;
                    break;
                } 
                else if(j >0 && j < 4 && a[j]){
                    a[j]--;
                    problem2 = 1;
                    break;
                }
                else if(j > 2 && a[j]){
                    problem3 = 1;
                    break;
                }
            }
            if(problem3 || problem1 || problem2){
                dfs(a,index)
            }

        }

    }
}

int main(void){
    int T;
    scanf("%d",&T);
    int a[5] = {0};
    for(int i = 0; i < T; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d",&a[j]);
        }

        printf("%d\n",dfs(a,0));
    }

    return 0;
}