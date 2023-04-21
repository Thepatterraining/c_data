#include<stdio.h>
#include<stdlib.h>

#define SIZE 5  //对SIZE进行宏定义，表示顺序表申请空间的大小

typedef struct List
{
    int *head;  //声明了一个名为head的长度不确定的数组，也叫“动态数组”
    int length; //记录当前顺序表的长度
    int size;   //记录顺序表分配的存储容量
}SqList;

SqList InitList();
void DisplayList(SqList L);

int main()
{
    SqList L = InitList();
    //向顺序表中添加元素
    for(int i = 0; i < L.size; i++)
    {
        L.head[i] = (i+1);
        L.length++;
    }
    printf("顺序表中存储的元素分别是：\n");
    DisplayList(L);
}

SqList InitList()
{
    SqList L;

    L.head = (int *)malloc(SIZE * sizeof(int));  //构造一个空的顺序表，动态申请存储空间
    
    if(!(L.head))   //如果申请失败，作出提示并直接退出程序
    {
        printf("初始化失败");
        exit(0);
    }

    L.size = SIZE; //空表的初始存储空间为SIZE
    L.length = 0;   //空表的长度初始化为0

    return L;
}

//输出顺序表中元素的函数
void DisplayList(SqList L)
{
    for(int i = 0; i < L.length; i++)
    {
        printf("%d ", L.head[i]);
    }
    printf("\n");
}