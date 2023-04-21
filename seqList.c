#include <stdio.h>
#include <stdlib.h>
#define ListSize 100

typedef int DataType;
typedef struct {
    DataType data[ListSize];
    int length;
} SeqList;

// 顺序表的初始化（置空表）
void InitList(SeqList *L) {
    int i;
    for(i = 0;i<ListSize; i++) {
        L->data[i] = 0;
    }
    L->length = 0;
}

//求表长度
int ListLength(SeqList L) {
    return L.length;
}

//遍历顺序表
void Traverse(SeqList L) {
    int i;
    for(i = 0; i < L.length; i++) {
        printf("%d \n", L.data[i]);
    }
}

//取表中第i个元素
DataType  GetNode(SeqList L, int i) {
    if (L.length == 0) {
        printf("empty");
        exit(0);
    }

    if (i < 1 || i > L.length + 1) {
        printf("position error");
        exit(0);
    }

    return L.data[i - 1];
}

//查找第一个值为x的元素，返回位置
int LocateNode(SeqList L, DataType x) {
    int i;
    for(i = 0; i <= L.length; i++) {
        if (L.data[i] == x) {
            return i+1;
        }
    }
    return -1;
}

//在第i个位置之前插入新元素
void InsertList(SeqList *L,int i, DataType x) {
    if (i < 1 || i > L->length + 1) {
        printf("position error");
        return;
    }

    //顺序表是否满了
    if (L->length >= ListSize) {
        printf("overflow");
        return;
    }

    //把从最后一个元素到要插入的i - 1的位置的元素全部向后移动一位，把i - 1的位置空出来让新元素插入
    int j;
    for(j = L->length - 1;j >= i-1; j--) {
        L->data[j + 1] = L->data[j];
    }

    //在I - 1的位置插入
    L->data[i - 1] = x;
    L->length++;
}

//删除L得第i个元素
DataType Delete(SeqList *L, int i) {
    if (L->length == 0) {
        printf("empty");
        exit(0);
    }

    if (i < 1 || i > L->length + 1) {
        printf("position error");
        exit(0);
    }

    /**
     * 把从要删除的i - 1的位置到最后一个位置的元素全部向前移动一位，把最后的元素删除
     */
    DataType x = L->data[i - 1]; //取出要删除的元素
    int j;
    for (j = i; j <= L->length; j++) { //$i = 1; $i < 3; $i--
        /**
         * 第一遍 $this->data = [1,2,2,3]; $i = 1;
         * 第二遍 $this->data = [1,2,3,3];$i = 2;
         */
        L->data[j - 1] = L->data[j]; 
    }
    L->length--;
    return x;
}

//输出顺序表中元素的函数
void DisplayList(SeqList L)
{
    for(int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main()
{
    SeqList L;
    //初始化
    InitList(&L);
    printf("初始化长度 %d \n", ListLength(L));
    InsertList(&L, 1, 1);
    printf("插入后长度 %d \n", ListLength(L));
    InsertList(&L, 1, 5);
    printf("插入后长度 %d \n", ListLength(L));
    //获取第1个元素
    printf("第1个元素 %d \n", GetNode(L, 1));
    printf("第2个元素 %d \n", GetNode(L, 2));
    // printf("第5个元素 %d \n", GetNode(L, 5));
    Traverse(L);
    printf("1的位置 %d \n", LocateNode(L, 1));
    printf("5的位置 %d \n", LocateNode(L, 5));
    printf("0的位置 %d \n", LocateNode(L, 0));
    //删除
    printf("删除5 %d \n", Delete(&L, 1));
    Traverse(L);
    // //向顺序表中添加元素
    // for(int i = 0; i < L.size; i++)
    // {
    //     L.head[i] = (i+1);
    //     L.length++;
    // }
    // printf("顺序表中存储的元素分别是：\n");
    // DisplayList(L);
}
