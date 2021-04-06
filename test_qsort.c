/* @date: 2021-04-01 11:32:52
@功能:
    stdlib库中自带的快速排序qsort();
@目的:

*/


#include <stdio.h>
#include <stdlib.h>
// self-definition's  compare function 
// when returns >0  a lies after b;
// when returns <0,a lies before b;
//when returns = 0, keep old sequence,not change
int comp(const void*a, const void*b) {
	return *(int*)a-*(int*)b;
}

int main() {
	int i=0;
	int *array;
	int n;
	scanf("%d",&n);
	array=(int*)malloc(n*sizeof(int));
 
	for(; i<n; i++) {
		scanf("%d",(array+i));
	}
	qsort(array, n, sizeof(int),comp);
	for(i=0;i<n;i++) {
		printf("%d\t",array[i]);
	}
	return 0;
}
