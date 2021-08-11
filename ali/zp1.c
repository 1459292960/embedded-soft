/* @date: 2021-08-11 10:28:39
    阿里秋招正式第一题，当时通过率50%,只是把每次要移动的次数就按照原来的次数一次ic移动，
    没有考虑到多次移动之后的算法。
@功能:
输入：
5 2
1 2 3 4 5
3 4

@目的:

*/


#include <stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node * pNext;
}NODE,* PNODE;

PNODE CreateList(PNODE pHead,int n){
    int i = 0;
    int temp = 0;
    PNODE pTail = pHead;
    for(i = 0; i < n; i++){
        scanf("%d",&temp);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        pNew->data = temp;
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pNew;
    }
    return pTail;
    
}
void TraverseList(PNODE pHead){
    PNODE q = pHead->pNext;
    int i = 0;
    while(q != NULL){
        if(i++) printf(" ");
        printf("%d",q->data);
        q  = q->pNext;
        
    }
    printf("\n");
}
// 改变位置
PNODE Change(PNODE pHead,PNODE pTail_original,int n){
    if(n == 0) return pTail_original;
    int i = 0;
    PNODE q = pHead;
    for(i = 0; i < n; i++){
        q = q->pNext;
    }

    PNODE p = q->pNext;// 指向即将挂在头节点下的
    pTail_original->pNext = pHead->pNext;
    pHead->pNext = p;
    q->pNext = NULL;
    return q;
}
int main(void){
    int n = 0,Q = 0;
    scanf("%d%d",&n,&Q);
    PNODE pHead = malloc(sizeof(NODE));
    PNODE pTail_original = CreateList(pHead,n);
    // TraverseList(pHead)
    int sum = 0,temp = 0;
    for(int i = 0; i < Q; i++){
        scanf("%d",&temp);
        sum +=temp;
    }
    sum  = sum%n;
    
    Change(pHead,pTail_original,sum);
    TraverseList(pHead);
    // Change(pHead,)


    
}

/*@在VScode中的输出：
---------------------------------
3 4 5 1 2
---------------------------------
@总结：

*/
