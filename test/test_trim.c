#include <stdio.h>
#include <string.h>

void fisrt_trim(char *strIn, char *strOut){

    int i, j ;

    i = 0;

    j = strlen(strIn) - 1;

    while(strIn[i] == ' ')
        ++i;

    while(strIn[j] == ' ')
        --j;
    strncpy(strOut, strIn + i , j - i + 1);
    strOut[j - i + 1] = '\0';
}
char * exam_trim(char *strIn){
    
        char *start = NULL, *end = NULL, *temp = NULL;//定义去除空格后字符串的头尾指针和遍历指针
        char *strOut = NULL;
        temp = strIn;

        while (*temp == ' '){
            ++temp;
        }

        start = temp; //求得头指针

        temp = strIn + strlen(strIn) - 1; //得到原字符串最后一个字符的指针(不是'\0')

        printf("%c\n", *temp);

        while (*temp == ' '){
            --temp;
        }

        end = temp; //求得尾指针
        

        for(strIn = start; strIn <= end; ){
            *strOut++ = *strIn++;
        }

    *strOut = '\0';
    return strOut;
}

char * trim(char * src){
    if(src == NULL || *src == '\0') return src;
    while(*src == ' ') src++;
    char * tail = src + strlen(src);
    while(*(--tail) == ' ')
        *(tail) = '\0';
    return src;
}
int main(void){
    char src[] = "  abc ";
    char * str = trim(src);
    printf("%s\n",str);
    return 0;
}