#include <stdio.h>
#define RATE 115200
#define STR1(x) x
#define STR2(x) STR1(#x)

int main(void){
    printf("%s\n",STR2(RATE));
    return 0;
}