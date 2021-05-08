#include <stdio.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node * pNext;
}NODE,* PNODE;
PNODE create_list(void){
    int len;
    int i ;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    for(int i = 0; i < 62; i++){
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        pNew->data = 0;
        pTail->pNext = pNew;
        if(i == 61) pNew->pNext = pHead->pNext; // 最后一次循环将尾结点指向首节点
        else   pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}
void setNumber_list(PNODE pHead,int pos){
    int i = 0;
    PNODE p = pHead;
    // 将p指向第pos个节点
    while(NULL != p && i < pos){
        p = p->pNext;
        ++i;
    }
    p->data++;
    return;
}
// 判断是否有相同的字符
bool same_char(PNODE pHead){
    PNODE p= pHead->pNext;
    for(int i = 0; i < 62;i++){
        if(p->data < 2){
            p = p->pNext;
            continue;
        }
        else return true;

    }
    return false;

}
// 需要变化的字符所在的位置
int pos_NC(PNODE pHead){
    PNODE p = pHead->pNext; // 指向首节点
    for(int i = 0; i < 62;i++){
        if(p->data < 2){
            p = p->pNext;
            continue;
        }
        else return i;
    }
}
// 离当前pos节点，最近的数为0的节点
int pos_Zero(PNODE pHead,int pos){
    PNODE p = pHead;
    int i = 0;
    int len = 0;
    // 将p指向第pos个节点，从pos从0开始算
    while(i < pos+1){
        p = p->pNext;
        ++i;

    }
    p = p->pNext;
    int j;
    for(j = 1; j < 62;j++){
        if(p->data == 0){
            return j;
        }
        else p = p->pNext;
    }
    if( j == 62) return 0;

}
// 各个字符都有了
bool full_list(PNODE pHead){
    PNODE p= pHead->pNext;
    for(int i = 0; i < 62;i++){
        if(p->data == 0){
            return false;
        }
        p = p->pNext;

    }
    return true;    
}
int cal_num(PNODE pHead){
    if(!same_char) return 0; // 读进来的全是不同的字符
    int sum = 0;
    while(1){
        int pos = pos_NC(pHead);
        sum += pos_Zero(pHead,pos);
        if(!same_char) return sum;
    }


}
int main(void){
    int n;
    scanf("%d",&n);
    char a[n];
    for(int i = 0; i < n; i++){
        scanf("%c",&a[i]);
    }
    PNODE pHead = create_list();
    int k = 0;

    for(int i < 0; i < n; i++){
        if(a[i]<'z' && a[i] > 'a'){
            k = a[i]-'a';
        }
        else if(a[i] < 'Z' && a[i] > 'A'){
            k=a[i]-'A'+26;

        }
        else{
            k = a[i]-'0'+52;
        }
        setNumber_list(pHead,k+1);
        
    }


    return 0;
}