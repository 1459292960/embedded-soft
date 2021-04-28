#include "stdio.h"
#include "stdlib.h"

int main(void){
    int flag = 0;
    int i,j,n;
    while(1){
        char s[100][1000];
        char * p[100];
        char * tmp;
        int endflag = 0;
        for(i = 0;;i++){
            for(j = 0;;j++){
                if(scanf("%c",&s[i][j]) == EOF){
                    flag = 1;
                    break;

                }
                printf("%c",s[i][j]);
                if(s[i][j] == ','){
                    break;
                }
                if(s[i][j] == '\n'){
                    endflag = 1;
                    break;
                }
            }
            if(flag) break;
            s[i][j] = '\0';
            p[i]=s[i];
            if(endflag){
                //printf("\n");
                break;
            }
        }
        if(flag) break;
        n = n+i;
        for(i = 0;i<n-1;i++){
            for(j = i+1;j<n;j++){
                if(strcmp(p[i],p[j]) > 0){
                    tmp = p[i];
                    p[i] = p[j];
                    p[j] = tmp;
                }
            }
        }
        for(i = 0;i < n-1; i++){
            printf("%s,",p[i]);
        }
        printf("%s\n",p[i]);

    }
    
    return 0 ;
}