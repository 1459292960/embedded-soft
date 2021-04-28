#include<stdio.h>
#include<string.h>

int main(void){
    char c;
    char str[100][100];
    int i = 0;
    while(1){
        if(scanf("%s",&str[i]) == EOF) break;
        // scanf("%c",&c);
        printf("%s\n",str[i]);
        c = getchar();
        if(c == '\n') printf("读到了换行符！！！\n");
        printf("%c",c);

        i++;
        // if(getchar() == '\n'){
        //     qsort(str,i,sizeof(str[0]),strcmp);
        //     for(int j = 0; j < i; j++){
        //         printf("%s ",str[j]);
        //     }
        //     printf("\n");
        //     i = 0;
            
        // }

    }
    return 0;
}