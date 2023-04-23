#include <stdio.h>
#include <stdlib.h>
#define ListSize 100

typedef int DataType; // 数据元素类型
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
    scanf("%d", &ch); //读入第一个字符
    while (ch != '\n') {
        //新建一个数据节点
        p = (ListNode*) malloc(sizeof(ListNode));
        p->data = ch;
        p->next = head;

        //头节点
        head = p;
        scanf("%d", &ch);
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
    scanf("%d", &ch); //读入第一个字符
    while (ch != -1) {
        //新建一个数据节点
        p = (ListNode*) malloc(sizeof(ListNode));
        p->data = ch;
        if (head == NULL) head = p; //新节点p插入空表
        else rear->next = p; //新节点p插入rear之后

        //尾指针指向新的尾巴节点
        rear = p;
        scanf("%d", &ch);
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
    scanf("%d", &ch);
    while (ch != -1) {
        /* code */
        //新建数据结点
        p = (ListNode *) malloc(sizeof(ListNode));
        p->data = ch;
        r->next = p;
        r = p;
        scanf("%d", &ch);
    }
    r->next = NULL;
    return head;
}

//单链表置空表
void InitListH(LinkList head) {
    head = (ListNode*) malloc(sizeof(ListNode));
    p = (ListNode*) malloc(sizeof(ListNode));
    p->next = NULL;
    head = p;
}

//单链表置空表
void InitList(LinkList head) {
    head = (ListNode*) malloc(sizeof(ListNode));
    head->next = NULL;
}

//不带头结点 遍历 按顺序逐一输出head指向的单链表的所有元素
void Traverse(LinkList head) {
    ListNode *p;
    p = head;
    while (p != NULL) {
        printf("%d \n", p->data);
        p = p->next;
    }
}

//带头结点 遍历 按顺序逐一输出head指向的单链表的所有元素
void TraverseH(LinkList head) {
    ListNode *p;
    p = head->next;
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

// 查找带头结点数据应该插入的位置
int SearchIndex(LinkList head, DataType x, int len) {
    ListNode *p;
    p = head->next;
    int i = 1;
    printf("查找的数据 %d,长度 %d \n", x, len);
    while (p != NULL && i < len) {
        printf("查找的数据 %d,p->data %d \n", x, p->data);
        if (p->data < x) {
            p = p->next;
            i++;
        } else {
            return i;
        }
    }
    return i;
}

// 插入排序
void InsertSort(LinkList head, int n) {
    ListNode *p;
    p = head->next;
    for(int i = 1; i<=n; i++) {
        //查找应该插入的位置
        int index = SearchIndex(head, p->data, i);
        printf("%d 应该插入的位置 %d \n", p->data, index);
        // 插入对应的位置
        InsertList( head, index, p->data);
        p = p->next;
        //删除已插入对应位置的元素
        DeleteList(head, i + 1);
    }
}

//从0到n之间选择出最大的一个数返回
int selectMax(LinkList head, int len) {
    ListNode *p;
    p = head->next;
    int i = 1;
    DataType max = 0;
    int maxIndex = 1;
    printf("选择的长度 %d \n", len);
    while (p != NULL && i < len) {
        printf("当前最大数 %d, 最大数的位置: %d, p->data %d \n", max, maxIndex, p->data);
        if (p->data >= max) {
            max = p->data;
            maxIndex = i;
        }
        p = p->next;
        i++;
    }
    return maxIndex;
}

// 选择排序
void SelectionSort(LinkList head, int n) {
    // n是待排序的最后一个下标
    while (n > 1)
    {
        /* code */
        //查找最大的一个数的位置
        int maxIndex = selectMax(head, n);
        printf("选择出的最大数位置 %d \n", maxIndex);
        //获取最大数
        ListNode* max = GetNodei(head, maxIndex);
        // 把最大的数放到待排序的最后面，也就是n + 1的位置
        InsertList(head, n + 1, max->data);
        // 删除原来的最大数
        DeleteList(head, maxIndex);
        n--;
    }
}

// 冒泡排序
void BubbleSort(LinkList head) {
    // 排序
    ListNode * pFirst;
    ListNode * pEnd;
    pEnd = NULL;
    pFirst = head->next;
    while (pFirst != pEnd)
    {
         while (pFirst->next != pEnd)
         {
            if (pFirst->data >= pFirst->next->data) {
                int temp = pFirst->data;
                pFirst->data = pFirst->next->data;
                pFirst->next->data = temp;
            }
            pFirst = pFirst->next;
         }
         pEnd = pFirst;
         pFirst = head->next;
         
    }
}

// 选择排序 书上的 不带头节点
void SelectSort(LinkList head) {
    // 先找最小的和第一个节点交换，再找次小的和第二个节点交换
    ListNode *p,*r,*s;
    ListNode q;
    p = head;
    // 假设链表不带头节点
    while (p != NULL)
    {
        s = p; // s为当前关键字最小节点地址指针
        r = p->next;
        // 像后比较，找关键字最小的节点
        while (r != NULL)
        {
            // 要是r比s小，就s指向r
            if (r->data < s->data) {
                s = r;
            }
            r = r->next;
        }
        // 说明有关键字比s小，交换位置
        if (s != p) {
            q = (*p);
            p->data = s->data;
            s->data = q.data;
        }
        p = p->next;
    }
    
}

// 选择排序 书上的 带头节点的
LinkList SelectSortH(LinkList head) {
    // 先找最小的和第一个节点交换，再找次小的和第二个节点交换
    ListNode *p, *q, *r, *s, *t, *t1;
    t = NULL; //置空，采用尾插入建立新表
    while (head != NULL)
    {
        s = head; // 假设s指向最小的节点
        p = head; // q指向p的前驱
        q = NULL;
        r = NULL; // r指向s的前驱
        while (p != NULL)
        {
            // 使s指向当前关键字小的节点
            if (p->data < s->data) {
                s = p;
                r = q; // r指向s的前一个
            }
            // 指向后继
            q = p;
            p = p->next;
        }
        // 没发现更小的
        if (s == head) {
            // 删除第一个节点
            head = head->next;
        } else {
            // 删除最小节点
            r->next = s->next;
        }
        if (t == NULL) {
            t = s;
            t1 = t; //t1指向新表的当前尾巴节点
        } else {
            t1->next = s;
            t1 = s;
        }
    }
    t1->next = NULL;
    return t;
}

//希尔排序

//快速排序

int main()
{
   LinkList l,l2;

   InitListH(l);
   InitListH(l2);
   l = CreateListRL();
//    SelectSort(l);
   l2 = SelectSortH(l);
   Traverse(l2);
//    InsertList(l, 1, 1);
// //    InsertList(l, 2, 2);
// //    InsertList(l, 3, 3);
//    Traverse(l);
//    printf("单链表长度 %d \n", getLength(l));
//    DataType x = DeleteList(l,1);
//    printf("删除1的元素 %d \n", x);
//    Traverse(l);
//    printf("单链表长度 %d \n", getLength(l));
   ListNode *p = GetNodei(l, 2);
   printf("第2个位置的数据 %d \n", p->data);
   ListNode *p2 = GetNodek(l, 2);
   printf("元素2 %d \n", p2->data);
//    InsertSort(l, getLength(l));
//    printf("排序完成的元素 \n");
//    Traverse(l);
}
