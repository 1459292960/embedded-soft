#include <stdio.h>
#include <string.h>

char * return_pstr(void){
    char * str  ="HELLO!";
    return str;
}
int main(void){
    char * str = return_pstr();
    char * str1 = "NIHAO";
   // strcpy(str1,"nihao");
    puts(str);
    printf("%s\n",str1);
}