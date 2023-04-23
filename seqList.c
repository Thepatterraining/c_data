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

//插入排序 书上的
void InsertSort(SeqList *L, int n) {
    int i,j;
    for(i = 1; i<=n; i++) {
        // 如果i < i-1 就移动
        if (L->data[i] < L->data[i - 1]) {
            // 取出当前记录，为哨兵
            DataType x = L->data[i];
            // 找插入位置
            for(j = i-1; x < L->data[j]; j--) {
                // 记录后移
                L->data[j+1] = L->data[j];
            }
            // 插入到正确位置
            L->data[j+1]=x;
        }
    }
}

// 希尔排序中的一趟插入排序， dk 为当前增量
void ShellInsert(SeqList *L, int dk, int n) {
    int i,j;
    // 将 L[dk - n] 分别插入有序区
    for (i = dk; i<=n; i++) {
        if (L->data[i] < L->data[i - dk]) {
            // 取出当前元素
            DataType x = L->data[i];
            j = i - dk;
            // 查找插入位置
            while (j >= 0 && x < L->data[j])
            {
                // 记录后移
                L->data[j + dk] = L->data[j];
                // 查找前一个
                j = j - dk;
            }
            // 插入
            L->data[j + dk] = x;
        }
    }
}

// 希尔排序
void ShellSort(SeqList *L, int d[], int t, int n) {
    int k;
    for(k = 0; k < t; k++) {
        ShellInsert(L, d[k], n);
    }
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

// 快速排序 对i - j之间的记录进行一次划分排序
int Partition(SeqList *L, int i, int j) {
    DataType x = L->data[i]; // 用区间的第一个记录为基准
    while (i < j)
    {
        // 从j所指位置向前搜索
        while (i < j && L->data[j] >= x)
        {
            j--;
        }
        // 后面大的数往前移动
        if (i < j) {
            L->data[i] = L->data[j];
            i++;
        }
        // 从i所指位置向后搜索
        while (i < j && L->data[i] <= x)
        {
            i++;
        }
        // 前面小的数往前移动
        if (i < j) {
            L->data[j] = L->data[i];
            j--;
        }
    }
    L->data[i] = x;
    return i;
}

// 快速排序
void QuickSort(SeqList *L, int low, int high) {
    int p;
    if (low < high) {
        p = Partition(L, low, high); // 做一次划分排序
        QuickSort(L, low, p - 1);  // 对左区间递归排序
        QuickSort(L, p + 1, high);  // 对右区间递归排序
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
            return mid; // 查找成功
        }
        if (L.data[mid] > x) {
            // 修改上界
            high = mid - 1;
        } else {
            // 修改下界
            low = mid + 1;
        }
    }
    return 0;
}

// 二分查找，递归
int BinSearch2(SeqList L, DataType x, int low, int high) {
    // 在区间 low - high内二分递归 low的初始值为1，high的初始值为n
    int mid;
    if (low <= high) {
        mid = (low + high) / 2;
        if (L.data[mid] == x) return mid; // 找到了
        if (L.data[mid] > x) {
            return BinSearch2(L, x, low, mid - 1); // 在左边查找
        } else {
            return BinSearch2(L, x, mid + 1, high); // 在右边查找
        }
    } else {
        return 0;
    }
}

// 书里面的选择排序
void SelectSort(SeqList *L, int n) {
    int i,j,k;
    // 做n - 1趟排序
    for (i = 0; i<n; i++) {
        // 设k为第i趟排序中关键字最小的记录位置
        k = i;
        // 在i - n选择关键字最小的记录位置
        for (j = i + 1; j <= n; j++) {
            // 有比 L.data[k] 小的，记住这个位置
            if (L->data[j] < L->data[k]) {
                k = j;
            }
        }
        // 和第i个记录交换
        if (k  != i) {
            DataType x = L->data[i];
            L->data[i] = L->data[k];
            L->data[k] = x;
        }
    }
}

int main()
{
    SeqList L;
    //初始化
    InitList(&L);
    printf("初始化长度 %d \n", ListLength(L));
    InsertList(&L, 1, 32);
    printf("插入后长度 %d \n", ListLength(L));
    InsertList(&L, 1, 76);
    printf("插入后长度 %d \n", ListLength(L));
    InsertList(&L, 1, 58);
    printf("插入后长度 %d \n", ListLength(L));
    InsertList(&L, 1, 43);
    printf("插入后长度 %d \n", ListLength(L));
    InsertList(&L, 1, 25);
    printf("插入后长度 %d \n", ListLength(L));
    InsertList(&L, 1, 65);
    printf("插入后长度 %d \n", ListLength(L));
    InsertList(&L, 1, 27);
    printf("插入后长度 %d \n", ListLength(L));
    InsertList(&L, 1, 48);
    printf("插入后长度 %d \n", ListLength(L));
    InsertList(&L, 1, 25);
    printf("插入后长度 %d \n", ListLength(L));
    InsertList(&L, 1, 36);
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
    // InsertSort(&L, ListLength(L) - 1);
    // SelectionSort(&L, ListLength(L));
    // BubbleSort(&L, ListLength(L));
    // int d[3] = {5,3,1};
    // ShellSort(&L, d, 3, ListLength(L) - 1);
    // QuickSort(&L, 0, ListLength(L) - 1);
    SelectSort(&L, ListLength(L) - 1);
    Traverse(L);
    printf("1的位置 %d \n", BinSearch(L, 25, ListLength(L)));
    printf("5的位置 %d \n", BinSearch(L, 27, ListLength(L)));
    printf("3的位置 %d \n", BinSearch(L, 76, ListLength(L)));
    printf("1的位置 %d \n", BinSearch2(L, 25, 1, ListLength(L)));
    printf("5的位置 %d \n", BinSearch2(L, 27, 1, ListLength(L)));
    printf("3的位置 %d \n", BinSearch2(L, 76, 1, ListLength(L)));
    // //向顺序表中添加元素
    // for(int i = 0; i < L.size; i++)
    // {
    //     L.head[i] = (i+1);
    //     L.length++;
    // }
    // printf("顺序表中存储的元素分别是：\n");
    // DisplayList(L);
}
