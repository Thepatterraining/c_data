#include <stdio.h>
#include <stdlib.h>
#define ListSize 100

typedef char DataType; // 数据元素类型
struct node {
    DataType data;
    struct node *next;
};
typedef struct node ListNode; // 结点类型
typedef ListNode *LinkList; // 结点指针类型
LinkList head; //头指针
ListNode *p; // 结点指针

//头插入建表
LinkList CreateListF() {
    LinkList head; //头指针
    ListNode *p; // 结点指针
    DataType ch; //数据
    
    head = NULL; //置空单链表
    ch = getchar(); //读入第一个字符
    while (ch != '\n') {
        //新建一个数据节点
        p = (ListNode*) malloc(sizeof(ListNode));
        p->data = ch;
        p->next = head;

        //头节点
        head = p;
        ch = getchar();
    }
    return head;
}

//尾插入建表
LinkList CreateListR() {
    LinkList head, rear; //头,尾指针
    ListNode *p; // 结点指针
    DataType ch; //数据
    
    head = NULL; //置空单链表
    rear = NULL; 
    ch = getchar(); //读入第一个字符
    while (ch != '\n') {
        //新建一个数据节点
        p = (ListNode*) malloc(sizeof(ListNode));
        p->data = ch;
        if (head == NULL) head = p; //新节点p插入空表
        else rear->next = p; //新节点p插入rear之后

        //尾指针指向新的尾巴节点
        rear = p;
        ch = getchar();
    }
    if (rear != NULL) rear->next = NULL; //尾巴指针置空
    return head;
}

//带头结点的尾插法建表
LinkList CreateListRL() {
    LinkList head = (ListNode*) malloc(sizeof(ListNode));
    ListNode *p,*r;
    DataType ch;
    r = head;
    ch = getchar();
    while (ch != '\n') {
        /* code */
        //新建数据结点
        p = (ListNode *) malloc(sizeof(ListNode));
        p->data = ch;
        r->next = p;
        r = p;
        ch = getchar();
    }
    r->next = NULL;
    return head;
}

//单链表置空表
void InitList(LinkList head) {
    head = (ListNode*) malloc(sizeof(ListNode));
    head->next = NULL;
}

//遍历 按顺序逐一输出head指向的单链表的所有元素
void Traverse(LinkList head) {
    ListNode *p;
    p = head;
    while (p != NULL) {
        printf("%d \n", p->data);
        p = p->next;
    }
}

//带头结点 按结点序号查找结点
ListNode * GetNodei(LinkList head, int i) {
    ListNode *p;
    int j;
    p = head->next;
    j = 1;
    while (p != NULL && j < i) 
    {
        p = p->next;
        ++j;
    }
    if (j == i) {
        return p;
    } else {
        return NULL;
    }
}

// 带头结点 按值查找
ListNode * GetNodek(LinkList head, DataType x) {
    ListNode *p;
    p = head;
    while (p != NULL) {
        printf("%d \n", p->data);
        if (p->data == x) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}


//带头结点 将值为x 的新结点插入到单链表L的第i个结点的位詈上
void InsertList(LinkList head,int i,DataType x) {
    ListNode *p, *s;
    int j;
    p = head; j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p == NULL) {
        printf("插入失败\n");
        exit(0);
    } else {
        s = (ListNode*) malloc(sizeof(ListNode));
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

//带头结点 删除 head 指向的单链表中的第i个结点
DataType DeleteList(LinkList head, int i) {
    ListNode *p, *s;
    DataType x;
    int j;
    p = head; j = 0;
    while (p != NULL && j < i - 1)
    {
        /* code */
        p = p->next;
        ++j;
    }
    if (p == NULL) {
        printf("位置错误\n");
        exit(0);
    } else {
        s = p->next;
        p->next = s->next;
        x = s->data;
        free(s);
        return x;
    }
}

//获得单链表的长度
int getLength(LinkList head) {
    int i = 0;
    ListNode *p;
    p = head->next;
    while (p != NULL) {
        p = p->next;
        ++i;
    }
    return i;
}

int main()
{
   LinkList l;

   InitList(l);
   l = CreateListRL();
   InsertList(l, 1, 1);
//    InsertList(l, 2, 2);
//    InsertList(l, 3, 3);
   Traverse(l);
   printf("单链表长度 %c \n", getLength(l));
   DataType x = DeleteList(l,1);
   printf("删除1的元素 %c \n", x);
   Traverse(l);
   printf("单链表长度 %c \n", getLength(l));
   ListNode *p = GetNodei(l, 2);
   printf("第2个位置的数据 %c \n", p->data);
   ListNode *p2 = GetNodek(l, 50);
   printf("元素2 %c \n", p2->data);
}
