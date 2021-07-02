/* @date: 2021-06-10 22:12:23 
    乐鑫笔试第二题，求出能去开会的员工数最多为多少
@功能:

@目的:

*/


#include<stdio.h>
#include<math.h> // 使用pow(x,m)，x的m次方函数

int main(void){
    int n = 0,k = 0;
    scanf("%d%d",&n,&k);
    int h = 1,sum = 1;
    // 求出完全2叉树的层数
    for(sum = 1;sum < n;h++){
        sum += pow(k,h);
    }
    // 求出前h-1层节点的个数
    sum = 0;
    for(int i = 1; i < h; i++){
        sum += pow(k,i-1);
    }
    int res = n - sum; // 第h层的节点
    int ans = res;
    int res_num = 0;
    // i代表层数，从h-1层一直遍历到第一层
    // 例如，第三层影响第二层，所以第一层只与第二层有关
    for(int i = h-1;i > 0;i--){
        res = pow(k,i-1)-(res+k-1)/k;
        ans += res;
    }

    int n = pow(2,3);
    printf("%d\n",n);
    return 0;
}