#include<stdio.h>
typedef struct{
    
    int a;
    char b;
    short c;
    char d;
    
}ST1;
int main(void){
    ST1 H;
    printf("%ld\n",sizeof(ST1));
    printf("%x\n",&H.a);
    printf("%x\n",&H.b);
    printf("%x\n",&H.c);
    printf("%x\n",&H.d);
    // printf("%ld\n",sizeof(ST3));
    return 0;
}

/*@在VScode中的输出：
---------------------------------
12
9f7b94dc
9f7b94e0
9f7b94e2
9f7b94e4
---------------------------------
@总结：

*/
