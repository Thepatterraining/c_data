#include <stdio.h>
#include <stdlib.h>
#define ListSize 100

typedef int DataType; // 数据元素类型
typedef struct StackNode {
    DataType data;
    struct StackNode *next;
}StackNode;
typedef StackNode* LinkStack; // 结点指针类型


//链栈 判断空
int StackEmpty(LinkStack top) {
    if(top == NULL) {
        return 1;
    }
    return 0;
}

//入栈
LinkStack Push(LinkStack top, DataType x) {
    StackNode *p;
    p = (StackNode*) malloc(sizeof(StackNode));
    p->data = x;
    p->next = top;
    top = p;
    return top;
}

//出栈
LinkStack Pop(LinkStack top, DataType *x) {
    if (StackEmpty(top)) {
        printf("空的");
        exit(0);
    }
    StackNode *p;
    p = top;

    *x = p->data;
    top = p->next;
    free(p);
    return top;
}

//获取栈顶元素
DataType GetTop(LinkStack top) {
    if (StackEmpty(top)) {
        printf("空的");
        exit(0);
    }
    return top->data;
}

int main()
{
    LinkStack top = NULL; //栈顶
    top = Push(top, 1);
    printf("获取栈顶元素 %d", GetTop(top));
    top = Push(top, 2);
    printf("获取栈顶元素 %d", GetTop(top));
    top = Push(top, 3);
    printf("获取栈顶元素 %d", GetTop(top));
    DataType x;
    top = Pop(top, &x);
    printf("出战 %d", x);
    top = Pop(top, &x);
    printf("出战 %d", x);
    top = Pop(top, &x);
    printf("出战 %d", x);
    top = Pop(top, &x);
    printf("出战 %d", x);
}
