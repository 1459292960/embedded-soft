#include <stdio.h>
void bubble_sort(int * a,int len){
    int temp;
    for(int i = 1; i < len; i++){
        for(int j = 0; j < len-i; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return ;
}
int main(void){
    int a[] = {4,5,6,2,5,2,-9};
    int len  = sizeof(a)/sizeof(a[0]);
    bubble_sort(a,len);
    for(int i = 0; i < len; i++){
        if(i) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}