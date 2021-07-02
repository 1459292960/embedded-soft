/* @date: 2021-07-02 20:39:04
    trim函数，去除字符串首尾的空格
@功能:

@目的:

*/


#include<stdio.h>
#include<string.h>

char * trim(char * src){

    if(src == NULL || *src == '\0') return src;
    while(*src == ' ') ++src;
    printf("bbbbb\n");
    char * tail = src+strlen(src);
    while(*(--tail) == ' ') *tail = '\0';
    return src;

}

int main(void){
    char p[] = "   aaa   ";
    printf("%s\n",trim(p));
    // int matrix[3][2] = {1,2,3,4,5,6};
    // int (*p)[3] = matrix;
    // p++;
    // printf("%d\n",(*p)[1]);
    return 0;
}