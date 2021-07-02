#include<stdio.h>
int b;
void fun(void){
    
    printf("Hello From fun.\n");
}
int main(void){
    fun();
    printf("%d\n",b);
    return 0;
}