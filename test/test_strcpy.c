/* @date: 2021-07-02 22:41:07
@功能:
    strcpy底层实现
@目的:

*/


#include "string.h"
#include "stdio.h"
char * my_strcpy(char * Dest, const char * Src){
    if(Src == NULL) return NULL; 
    char * addr = Dest;
    while((*Dest++ = *Src++) != '\0');
    return addr;
}


int main(void){
    char str1[10] = "TsinghuaOK"; // 字符数组
    // puts(str1);
    char str2[10] = {"Computer"};
    //puts(str2);
    my_strcpy(str1,str2);
    printf("%s\n",str1);
    return 0;
}

/*@在VScode中的输出：
---------------------------------
Computer
---------------------------------
@总结：

*/
