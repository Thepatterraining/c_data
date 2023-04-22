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

//插入排序
// void InsertSort(SeqList *L, int n) {
//     int i,j;
//     for(i = 2; i<=n; i++) {
//         if (L->data[i] < L->data[i - 1]) {
//             L->data[0] = L->data[i];
//             for(j = i-1; L->data[0] < L->data[j]; j--) {
//                 L->data[j+1] = L->data[j];
//             }
//             L->data[j+1]=L->data[0];
//         }
//     }
// }

void ShellSort(SeqList *L, int n) {

}

// 冒泡排序
void BubbleSort(SeqList *L, int n) {
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            //判断相邻的两个的大小
            if (L->data[i] > L->data[j]) {
                //如果前面的比后面的大，也就是i比j大，那么两个互换，因为从小到大，所以前面的i应该比j小才对
                int temp = L->data[j];
                L->data[j] = L->data[i];
                L->data[i] = temp;
            }
        }
    }
}

//快排
// SeqList * QuickSort(SeqList *L, int n) {
//     //递归终止条件，当只有一个的时候直接返回
//     if (n <= 1) {
//         return L;
//     }
//     //取第一个当中位数
//     int mid = L->data[0];
//     SeqList* left, *right, *lsort, *rsort;
//     InitList(left);
//     InitList(right);
//     InitList(lsort);
//     InitList(rsort);
//     int i,li,ri;
//     li = 0;
//     ri = 0;
//     //循环一遍，小于的放左边，大于的放右边
//     for (i = 1; i < n; i++) {
//         if (L->data[i] >= mid) {
//             right->data[ri] = L->data[i];
//             ri++;
//         } else {
//             left->data[li] = L->data[i];
//             li++;
//         }
//     }

//     //左右递归
//     lsort = QuickSort(left, n);
//     rsort = QuickSort(right, n);
    
//     //合并左边，中位数和右边
    
// }

// // 查找带头结点数据应该插入的位置
// int SearchIndex(SeqList *L, DataType x, int len) {
//     int i;
//     DataType max = 0;
//     int maxIndex = len - 1;
//     printf("插入的有序长度 %d \n", len);
//     for(i = len - 1; i >= 0; i--) {
//         printf("查找的数据 %d,L.data %d \n", x, L->data[i]);
//         if (L->data[i] <= x) {
//             return i + 1;
//         }
//     }
// }

// // 插入排序
// void InsertSort(SeqList *L, int n) {
//     for(int i = 1; i<=n; i++) {
//         //查找应该插入的位置
//         int index = SearchIndex(L, L->data[i], i);
//         printf("%d 应该插入的位置 %d \n", L->data[i], index);
//         // 插入对应的位置
//         InsertList(L, index, L->data[i]);
//         //删除已插入对应位置的元素
//         Delete(L, i);
//     }
// }

int selectMax(SeqList *L, int len) {
    int i;
    DataType max = 0;
    int maxIndex = len - 1;
    printf("选择的长度 %d \n", len);
    for(i = len - 1; i >= 0; i--) {
        printf("当前最大数 %d, 最大数的位置: %d, L.data %d \n", max, maxIndex, L->data[i]);
        if (L->data[i] >= max) {
            max = L->data[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

// 选择排序
void SelectionSort(SeqList *L, int n) {
    // n是待排序的最后一个下标
    while (n > 1)
    {
        /* code */
        //查找最大的一个数的位置
        int maxIndex = selectMax(L, n);
        printf("选择出的最大数位置 %d \n", maxIndex);
        //获取最大数
        DataType max = L->data[maxIndex];
        printf("最大数 %d \n", max);
        L->data[maxIndex] = L->data[n - 1];
        L->data[n - 1] = max;
        n--;
    }
}

// 二分查找
int BinSearch(SeqList L, DataType x, int n) {
    int low = 1,mid, high = n;
    while (low <= high)
    {
        /* code */
        mid = (low + high) / 2;
        if (L.data[mid] == x) {
            return mid;
        }
        if (L.data[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
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
    InsertList(&L, 1, 3);
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
    // printf("删除5 %d \n", Delete(&L, 1));
    InsertSort(&L, ListLength(L));
    Traverse(L);
    printf("1的位置 %d \n", BinSearch(L, 1, ListLength(L)));
    printf("5的位置 %d \n", BinSearch(L, 5, ListLength(L)));
    printf("3的位置 %d \n", BinSearch(L, 3, ListLength(L)));
    // //向顺序表中添加元素
    // for(int i = 0; i < L.size; i++)
    // {
    //     L.head[i] = (i+1);
    //     L.length++;
    // }
    // printf("顺序表中存储的元素分别是：\n");
    // DisplayList(L);
}
