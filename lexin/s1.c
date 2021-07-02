#include<stdio.h>

void bubble_sort(int * a,int len){
    int temp;
    for(int i = 0; i < len-1; i++){
        for(int j = 0; j < len -i-1; j++){
            if(a[j]<a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp; 
            }
        }
    }
}

int main(void){

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int s[n],N[n];
    int c[n];

    for(int i = 0; i < n; i++){
        scanf("%d%d",&s[i],&N[i]);
    }
    // for(int i = 0; i < n; i++){

    //     printf("%d %d\n",s[i],N[i]);
    // }
    for(int i = 0; i < n; i++){
        c[i] = (k-s[i])*N[i];
    }
    bubble_sort(c,n);
    int max = 0;
    for(int i = 0; i < m; i++){
        max += c[i];
        
    }
    printf("%d\n",max);

}