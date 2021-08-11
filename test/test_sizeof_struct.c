#include <stdio.h>

typedef struct{
    char a;
    int b;
    char c;

}test1;

typedef struct{
    char d;
    test1 e;
    char f;

}node;

int main(void){
    printf("%ld\n",sizeof(test1));
    printf("%ld\n",sizeof(node));
    return 0;
}