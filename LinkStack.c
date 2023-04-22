#include <stdio.h>
#include <stdlib.h>
#define ListSize 100

typedef int DataType; // 数据元素类型
typedef struct StackNode {
    DataType data;
    struct StackNode *next;
}StackNode;
typedef StackNode* LinkStack; // 结点指针类型
LinkStack top; //栈顶


//链栈 判断空
int StackEmpty(LinkStack top) {
    if(top->next == NULL) {
        return 1;
    }
    return 0;
}

//入栈
void Push(LinkStack top, DataType x) {
    StackNode *p;
    p = (StackNode*) malloc(sizeof(StackNode));
    p->data = x;
    p->next = top->next;
    top->next = p;
}

//出栈
DataType Pop(LinkStack top) {
    if (StackEmpty(top)) {
        printf("空的");
        exit(0);
    }
    StackNode *p;
    p = top->next;

    DataType x = p->data;
    top->next = top->next->next;
    return x;
}

//获取栈顶元素
DataType GetTop(LinkStack top) {
    return top->next->data;
}

int main()
{
}
