#include<stdio.h>
#include<string.h>
void count(int* a,int b){

    static int c = 0;
    *a = ++c+*a+b;
    return;
}

int main(void){

    char * str = NULL;
    int i,sum = 0;
    str = (char*)malloc(16);
    memset(str,'0',16);
    strcpy(str,"12345678");
    printf("%d\n",sizeof(str));
    for(i = 0; i < sizeof(str); i++ ){


        count(&sum,str[i]-'0');
    }
    printf("%d\n",sum);

    printf("%ld\n",sizeof(0XAABBCCDD));
    return 0;
}