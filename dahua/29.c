
#include<stdio.h>

int x = 10;
int modifyvalue(){

    return (x+=10);
}
int changevalue(int x){

    return (x+=1);
}

int main(void){
    int x = 10;
    x++;
    changevalue(x); // 传入的是局部变量
    x++;
    modifyvalue();
    printf("%d\n",x);
    x++;
    changevalue(x);
    printf("%d\n",x);
    modifyvalue();
    printf("%d\n",x);
    printf("%d\n%d\n",sizeof(long),sizeof(long long));
    return 0;
}