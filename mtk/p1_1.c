/* @date: 2021-07-14 21:45:07
    萌哥的代码，联发科提前批笔试
@功能:

@目的:

*/



#include<stdio.h>
#include<stdlib.h>
typedef struct n{
    int data;
    struct n *next;
    struct n *pre;
    
}node,*pnode;
//创建节点
pnode creatNode(int val){
    pnode ret = (pnode)malloc(sizeof(pnode));
    ret->data = val;
    ret->pre = ret->next = NULL;
    return ret;
}

int main(){
    printf("%ld %ld\n",sizeof(node),sizeof(pnode));
    int nums[100] = {0};
    int num;
    int cnt = 0;
    while(scanf("%d", &num) != EOF){
        nums[cnt++] = num;
    }
    int insert = nums[cnt - 1];
    cnt--;

    //创建以虚拟头节点开始的双链表
    pnode ret = creatNode(0);
    pnode p = ret;
    for(int i = 0; i < cnt; i++){
        pnode tmp = creatNode(nums[i]);
        p->next = tmp;
        tmp->pre = p;

        p = p->next;
    }
    
    //插入
    p = ret->next;
    int flag = 0;
    while(p){
        if(p->data >= insert){
            pnode tmp = creatNode(insert);
            tmp->next = p;
            tmp->pre = p->pre;
            tmp->pre->next = tmp;
            tmp->next->pre = tmp;
            flag = 1;
            break;
        }
        p = p->next;
    }
    
    //当插入值在最后是的处理
    if(flag == 0){
        p = ret->next;
        while(p->next){
            p = p->next;
        }
        pnode tmp = creatNode(insert);
        p->next = tmp;
        tmp->pre = p;
    }
    
    //遍历输出
    pnode head = ret->next;
    int i = 0;
    while(head){
        i++ && printf(" ");
        printf("%d", head->data);
        head = head->next;
    }
    //printf("%d\n", cnt);
}