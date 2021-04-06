#include "assert.h"
#include "stdio.h"

int i = 10;
int main(void){
    assert(i>9);
    i++;
    printf("%d\n",i);
    return 0;
}