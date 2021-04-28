#include <stdio.h>
#include <string.h>
int main(void){
    int num[26];
    char * s = "rat";
    int n = strlen(s); // length of string ,note that "\0" was  not counted

    printf("n = %d\n",n);

    int k = s[0]-'a';
    printf("k = %d\n",k);
    int j= 'a'+1;
    printf("short = %d\n",sizeof(short));
    printf("int  = %d\n",sizeof(int));
    printf("%c\n",0); // NULL对应的ASCII码为0
    printf("%ld\n",sizeof(num));
    return 0;
}