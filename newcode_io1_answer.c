#include <stdio.h>
#include <string.h>

// scanf：
// 除空格字符外的普通字符必须与输入严格匹配，除%c外其他转换说明都会自动跳过待输入值前面所有的空白
// 若格式说明字符之间有逗号，且在逗号前加空白，则逗号前后有无空格的输入均可识别ok
// 格式字符串中的空白意味着跳过下一个输入项前面的所有空白（C Primer Plus P95）
//（注scanf(" %c",&ch)是从第一个非空白字符开始读取；而scanf("%c",&ch)是从输入中的第一个字符开始读取）

int main()
{
    int flag = 0;
    int i,j,n;
    while(1){
        char s[100][1000];
        char *p[100]; // 内含100个指针变量（指向字符类型）的数组
        char *tmp;
        int endflag=0;
        for(i=0;;i++){
            for(j=0;;j++){
                if(scanf("%c",&s[i][j])==EOF){ // 注意此处若没有空格，则%s会输入整个字符串，所以需要按字符读取处理
                    flag = 1; // 读取输入完毕
                    break;
                }
               // printf("%c",s[i][j]);
                if(s[i][j]==','){
                    break;
                }
                if(s[i][j]=='\n'){
                    endflag = 1;
                    break;
                }
            }
            // 当已到达文件结尾即scanf返回值为EOF时，并不会有endflag为1，会导致死循环而数组越界等
            if(flag){ // 注意此处也要判断用以退出循环，否则会发生段错误....!!
                break;
            }
            // 注意每行的最后一个单词也要加结束符\0，并完成赋值操作
            // !! 此上下3处顺序很重要，易出现段错误情况，注意仔细处理，定位了好久...
            s[i][j]='\0'; // 替换逗号，给单词加上结束符
            p[i] = s[i];
 //           printf("%s\n",p[i]);

            if(endflag){ // 该行输入完毕
  //              printf("\n");
                break;
            }
        }
        if(flag){
            break;
        }
        // 下面的排序与字符串排序（1）字符串排序（2）大致相同
        n = i+1;
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(strcmp(p[i],p[j])>0){
                    tmp = p[i];
                    p[i] = p[j];
                    p[j] = tmp;
                }
            }
        }
        for(i=0; i<n-1; i++){
            printf("%s,",p[i]);
        }
        printf("%s\n",p[i]);
    }

    return 0;
}