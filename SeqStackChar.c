#include <stdio.h>
#include <stdlib.h>
#define StackSize 100

typedef int DataType;
typedef struct {
    DataType data[StackSize];
    int top;
} SeqStack;

// 顺序栈，置空
void InitStack(SeqStack *S) {
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
    } else {
        S->top++;
        S->data[S->top] = x;
    }
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

// 圆括号匹配
int Expr() {
    SeqStack S;
    DataType ch,x;
    InitStack(&S);
    ch = getchar();
    while (ch != '\n')
    {
        /* code */
        if (ch == '(') {
            Push(&S,ch);
        }else {
            if (ch == ')') {
                if (StackEmpty(&S)) {
                    return 0;
                } else {
                    x = Pop(&S);
                }
            }
        }
        ch = getchar();
    }
    if (StackEmpty(&S))  return 1;
    else return 0;
}

//字符串回文
int Symmetry(char str[]) {
    SeqStack S;
    int j,k,i=0;
    InitStack(&S);
    while (str[i] != '\0')
    {
        /* code */
        i++;
    }
    for(j = 0; j < i/2; j++) {
        Push(&S, str[j]);
    }
    k = (i+1) / 2;
    for(j=k; j<i; j++) {
        if (str[j] != Pop(&S)) {
            return 0;
        }
    }
    return 1;
}

// 数值转化 将一个非负数十进制数N 转化成 d 进制的数
void conversion(int N, int d) {
    SeqStack S;
    InitStack(&S);
    while (N)
    {
        /* code */
        Push(&S, N % d);
        N = N / d;
    }

    while (!StackEmpty(&S))
    {
        /* code */
        DataType i = Pop(&S);
        printf("%d", i);
    }
}

int main()
{
    // SeqStack S;
    // InitStack(&S);
    // printf("是空的 %d", StackEmpty(&S));
    // Push(&S, 1);
    // Push(&S, 2);
    // Push(&S, 3);
    // printf("不是空的 %d", StackEmpty(&S));
    // printf("获取栈顶元素 %d", GetTop(&S));
    // printf("出栈元素 %d", Pop(&S));
    // printf("出栈元素 %d", Pop(&S));
    // printf("出栈元素 %d", Pop(&S));
    // printf("是空的 %d", StackEmpty(&S));
    // printf("判断圆括号 %d", Expr());
    // char str[5] = {'a','b','b','c','\0'};
    // printf("判断回文 %d", Symmetry(str));
    conversion(6,2);
}
