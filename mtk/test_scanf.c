#include<stdio.h>

int main(void){
    char a[100];
    scanf("%[^,\n]s",a);
    printf("%s\n",a);
    return 0;
}