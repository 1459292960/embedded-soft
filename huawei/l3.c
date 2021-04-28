/*@date:2021-04-28
    李圣华为实习生笔试第一题
@功能:
    
@目的:
    
*/


#include <stdio.h>
// 字符串反转
char * revstr(char *str, size_t len)
{

    char    * start = str;
    char    * end = str + len - 1;
    char    ch;

    if (str != NULL)
    {
        while (start < end)
        {
            ch = *start;
            *start++ = *end;
            *end-- = ch;
        }
    }
    return str;
}

int main(void){
    char s[10000];
    char * pstr = NULL;
    scanf("%s",s);
    int length;
    int num_left[10000] ={0},num_right[10000] = {0} ;

    // 字符串长度
    for(length = 0; ;length++){
        if(s[length] == '\0') break;
    }


    // pstr = revstr(s,length);
    // printf("%d",length);
    // printf("%s\n",pstr);
    for(int i = 0; i < length; i++){
        if(s[i] == '(') num_left[i] = 1;
        if(s[i] == ')') num_right[i] = 1;

    }    

 
      

 

    return 0;
}