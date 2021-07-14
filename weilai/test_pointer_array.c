#include<stdio.h>

int main(void){
    char * buff[] = {"char","int","double"};
    printf("%c\n",(*(buff+1)[1]));
    return 0;
}