#include <stdio.h>
#include <stdlib.h>
#define QueueSize 5

typedef char DataType;
typedef struct {
    DataType data[QueueSize];
    int front;
    int rear;
} CirQueue;

// 顺序队列置空
void InitQueue(CirQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
}

// 判断队列空
int QueueEmpty(CirQueue *Q) {
    return Q->front == Q->rear;
}

// 判断队列满
int QueueFull(CirQueue *Q) {
    return (Q->rear + 1) % QueueSize == Q->front;
}

//入栈
void EnQueue(CirQueue *Q, DataType x) {
    if (QueueFull(Q)) {
        printf("满了");
    } else {
        Q->data[Q->rear] = x;
        Q->rear = (Q->rear + 1) % QueueSize;
    }
}

//出栈
DataType DeQueue(CirQueue *Q) {
    if (QueueEmpty(Q)) {
        printf("空的");
        exit(0);
    }

    DataType x = Q->data[Q->front];
    Q->front = (Q->front + 1) % QueueSize;
    return x;
}

// 取队列头元素
DataType GetFront(CirQueue *Q) {
    if (QueueEmpty(Q)) {
        printf("空的");
        exit(0);
    }

    DataType x = Q->data[Q->front];
    return x;
}


int main()
{
    CirQueue Q;
    InitQueue(&Q);
    printf("队列是空的 %d", QueueEmpty(&Q));
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);
    EnQueue(&Q, 5);
    EnQueue(&Q, 6);
    printf("队列第一个元素 %d", GetFront(&Q));
    printf("出队列 %d", DeQueue(&Q));
    printf("出队列 %d", DeQueue(&Q));
    printf("出队列 %d", DeQueue(&Q));
    printf("出队列 %d", DeQueue(&Q));
    printf("出队列 %d", DeQueue(&Q));
}
