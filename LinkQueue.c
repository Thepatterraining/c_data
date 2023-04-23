#include <stdio.h>
#include <stdlib.h>
#define QueueSize 100

typedef int DataType;

typedef struct qnode {
    DataType data;
    struct qnode *next;
} QueueNode; // 链队列结点类型


typedef struct {
    QueueNode *front;
    QueueNode *rear;
}LinkQueue;

// 构造空队列
void InitQueue(LinkQueue *Q) {
    Q->front = (QueueNode *) malloc(sizeof(QueueNode)); //申请头节点
    Q->rear = Q->front;
    Q->rear->next = NULL;
}

//链队列 判断空
int QueueEmpty(LinkQueue *Q) {
    return Q->rear == Q->front;
}

//入队列
void EnQueue(LinkQueue *Q, DataType x) {
    QueueNode *p;
    p = (QueueNode*) malloc(sizeof(QueueNode));
    p->data = x;
    p->next = NULL;
    Q->rear->next = p; // p 放到原来队列尾巴之后
    Q->rear = p; // 队列尾巴指针指向新的元素
}

//出栈
DataType DeQueue(LinkQueue *Q) {
    if (QueueEmpty(Q)) {             
        printf("空的");
        exit(0);
    }
    QueueNode *p;
    p = Q->front; //p指向头节点

    Q->front = Q->front->next; // 头指针指向原来的队列头节点

    free(p);
    return Q->front->data;
}

//获取队列头元素
DataType GetFront(LinkQueue *Q) {
    if (QueueEmpty(Q)) {
        printf("空的");
        exit(0);
    }
    return Q->front->next->data;
}

int main()
{
    LinkQueue Q;
    InitQueue(&Q);
    printf("是空的 %d \n", QueueEmpty(&Q));
    EnQueue(&Q, 5);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);
    EnQueue(&Q, 5);
    printf("不是空的 %d \n", QueueEmpty(&Q));
    printf("获取队列头元素 %d \n", GetFront(&Q));
    printf("出队 %d \n", DeQueue(&Q));
    printf("出队 %d \n", DeQueue(&Q));
    printf("出队 %d \n", DeQueue(&Q));
    printf("出队 %d \n", DeQueue(&Q));
    printf("出队 %d \n", DeQueue(&Q));
    printf("出队 %d \n", DeQueue(&Q));
}
