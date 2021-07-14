/* @date: 2021-07-14 21:46:00
    自己的代码,需要注意的地方，多次使用的代码部分，最好封装成函数进行调用
@功能:
    两行数据，第一行为已排序的链表第二行为新插入节点的值，将其插入链表中使新链表有序
@目的:

*/


#include<stdio.h>
#include<malloc.h>
// 定义一个节点
typedef struct n{
    int data;
    struct n * next;
    struct n * pre; 
}node,*pnode;


// 创建一个双链表
pnode CreateList(void){
    pnode pHead = (pnode)malloc(sizeof(node));
    pHead->next=  pHead->pre = NULL; // 初始化，否则该指针可能指向不该其他的内存空间
    pnode pTail = pHead;
    int num;
    char c;
    while(scanf("%d",&num) != EOF){
        pnode pNew  = (pnode)malloc(sizeof(node));
        pNew->data = num;
        pNew->next = NULL;
        pNew->pre = pTail;
        pTail->next = pNew;
        pTail = pNew;
        scanf("%c",&c);
        if(c == '\n') break;


    }
    return pHead;
}

void TraverseList(pnode pHead){

    pnode p = pHead->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    return ;
}
pnode InsertList(pnode pHead,int value){
    pnode pNew = (pnode)malloc(sizeof(node));
    pNew->data = value;
    pnode p = pHead->next;
    pnode q;
    while(p!= NULL){
        if(p->data >= pNew->data){
            break;
        }
        q = p; // 新节点要放在最后一个时，q指向最后一个节点
        p = p->next;
    }
    // 新节点在最后
    if(p == NULL){
        q->next = pNew;
        pNew->next = NULL;
        pNew->pre = q;
    }
    // 新节点不在最后一个位置
    else{
        q = p->pre;
        pNew->next = p;
        pNew->pre = q;
        q->next = pNew;
        p->pre = pNew;

    }
    
    return pHead;

}
int main(void){
    pnode pHead = CreateList();
    // TraverseList(pHead);
    int value = 0;
    scanf("%d",&value);
    pHead =InsertList(pHead,value);
    // printf("\n");
    TraverseList(pHead);
    return 0;
}