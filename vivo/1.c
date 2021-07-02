/* @date: 2021-06-18 20:41:52
    C为轮船的载重；
    W[i]中为各个物品的重量；
    V[i]为各个物品的价值
@功能:
    求出轮船能装载的货物的最大价值
@目的:

*/


#include<stdio.h>
#include<stdlib.h>

int ans[10000005];

// typedef struct{
//     int w;
//     int v;
// }HW;

int max (int a, int b) {
    if (a >= b) return a;
    else return b;
}
int main(void){
    int C;
    int W[500]={0},V[500]={0}; // 物品重量和价值
    scanf("%d",&C);
    // printf("%d\n",C);
    // char B = getchar();
    // printf("%c",B);
    int i = 1;
    int j = 1;
    // HW Y[500] = {0}; 
    while(scanf("%d",&W[i++]) != EOF){
        char B = getchar();
        if(B == '\n') break;
        
        
    }
    int num = i;
    while(scanf("%d",&V[j++]) != EOF){
        char B = getchar();
        if(B == '\n') break;
        
        
    }
    // for(int k = 0; k < num;k++){
    //     Y[k].w = W[k];
    //     Y[k].v = V[k];
    //     // printf("%d  %d\n",W[k],V[k]);
    // }
    // for(int k = 0; k < num;k++){
    //     for(int j = 0; j < num)
    // }

    for (int m = 1; m <= i; m++) {
        for (int n = C; n > 0; n--) {
            if (n < W[m]) break;
            else {
                ans[n] = max(ans[n], ans[n - W[m]] + V[m]);
            }
        }
    }
    printf("%d\n", ans[C]);
    return 0;
}