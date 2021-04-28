#include <stdio.h>

int main(void){
    int x = 0,y =0;
    int temp;
    scanf("%d%d",&x,&y);
    int a[x+y];
    for(int i = 0; i < x+y;i++){
        scanf("%d",&a[i]);
        // if(i == (x-1)) scanf("^[]");
        // else getchar();
        // getchar();
        
    }
    //   for(int i = 0 ; i < x+y; i++){
    //     printf("%d",a[i]);
    // }  
    // printf("\n");
    // putchar('\101');
    for(int i = 0; i < x+y-1; i++){
        for(int j = 0; j < x+y-i-1;j++){
            if(a[j] > a[j+1]){
               temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i = 0 ; i < x+y; i++){
        printf("%d ",a[i]);
    }

    return 0;
}