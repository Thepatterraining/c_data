#include <stdio.h>
#include <stdlib.h>
#define StackSize 100

typedef int DataType;
typedef struct {
    DataType data[StackSize];
    int top;
} SeqStack;

// 顺序栈，置空
void InitList(SeqStack *S) {
    int i;
    for(i = 0;i<StackSize; i++) {
        S->data[i] = 0;
    }
    S->top = -1;
}

// 判断栈空
int StackEmpty(SeqStack *S) {
    if (S->top == -1) {
        return 1;
    }
    return 0;
}

// 判断栈满
int StackFull(SeqStack *S) {
    if (S->top == StackSize  - 1) {
        return 1;
    }
    return 0;
}

//入栈
void Push(SeqStack *S, DataType x) {
    if (StackFull(S)) {
        printf("满了");
        exit(0);
    }
    S->top++;
    S->data[S->top] = x;
}

//出栈
DataType Pop(SeqStack *S) {
    if (StackEmpty(S)) {
        printf("空的");
        exit(0);
    }

    DataType x = S->data[S->top];
    S->top--;
    return x;
}

// 取栈顶元素
DataType GetTop(SeqStack *S) {
    if (StackEmpty(S)) {
        printf("空的");
        exit(0);
    }

    DataType x = S->data[S->top];
    return x;
}


int main()
{
    SeqStack *S;
    InitList(S);
    printf("是空的 %d", StackEmpty(S));
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    printf("不是空的 %d", StackEmpty(S));
    printf("获取栈顶元素 %d", GetTop(S));
    printf("出栈元素 %d", Pop(S));
    printf("出栈元素 %d", Pop(S));
    printf("出栈元素 %d", Pop(S));
    printf("是空的 %d", StackEmpty(S));
}
