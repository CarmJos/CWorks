#include <stdio.h>

#define MAX 11

/*1.冒泡排序*/
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*冒泡排序*/
void Bubble_Sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*2.插入排序 */
void Insertion_Sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // 移动数组中比key大的元素
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*3.希尔排序 */
void Shell_Sort(int A[], int h[], int N, int t) {
    int i, j, k;
    int temp;
    for (k = 0; k < t; k++) {    /* t轮的插入排序 */
        int gap = h[k];
        for (i = gap; i < N; i++) {
            temp = A[i];
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) {
                A[j] = A[j - gap];
            }
            A[j] = temp;
        }
    }
}

/*4.简单选择排序 */
// 寻找最小值的下标
int ScanForMin(int arr[], int n) {
    int i, j, min_idx, temp;
    // 一一选择元素
    for (i = 0; i < n - 1; i++) {
        min_idx = i; // 记录当前最小元素的索引
        // 在未排序部分中寻找最小元素
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        // 交换找到的最小元素和当前元素
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    return min_idx;
}

void Selection_Sort(int A[], int N) {

}

/*5.堆排序 */

/*对A[N]从第i个元素开始向下迁移调整 */
void Adjust(int arr[], int n, int i) {
    int largest = i; // 初始化为根节点
    int left = 2 * i + 1; // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点大于根节点
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于根节点
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根节点，交换它们并继续堆化
    if (largest != i) {
        Swap(&arr[i], &arr[largest]);
        Adjust(arr, n, largest);
    }
}

// 主函数，用于执行堆排序
void Heap_Sort(int arr[], int n) {
    // 建立最大堆
    for (int i = n / 2 - 1; i >= 0; i--)
        Adjust(arr, n, i);

    // 一个接一个地从堆中取出元素
    for (int i = n - 1; i > 0; i--) {
        // 移动当前根到数组的末尾
        Swap(&arr[0], &arr[i]);

        // 调整堆
        Adjust(arr, i, 0);
    }
}


/*6.计数排序 */
void Count_Sort(int A[], int N) {
}

/*7.归并排序 */
// 合并操作
void Merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // 创建临时数组
    int L[n1], R[n2];

    // 拷贝数据到临时数组 L[] 和 R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // 合并临时数组到原数组
    i = 0; // 初始化左子数组索引
    j = 0; // 初始化右子数组索引
    k = l; // 初始化合并子数组索引
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝剩余元素（如果有）
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 主函数，用于递归排序和合并
void M_Sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // 递归排序左右子数组
        M_Sort(arr, l, m);
        M_Sort(arr, m + 1, r);

        // 合并排序后的子数组
        Merge(arr, l, m, r);
    }
}



/*8.快速排序 */

// 分区函数
int Partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = (low - 1); // 较小元素的索引

    for (int j = low; j <= high - 1; j++) {
        // 如果当前元素小于或等于基准
        if (arr[j] <= pivot) {
            i++; // 增加较小元素索引
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// 主函数，用于递归排序
void Quick_Sort(int arr[], int low, int high) {
    if (low < high) {
        // 分区索引
        int pi = Partition(arr, low, high);

        // 分别对分区进行排序
        Quick_Sort(arr, low, pi - 1);
        Quick_Sort(arr, pi + 1, high);
    }
}

int main() {
    int A[7] = {25, 57, 48, 37, 12, 92, 86};
    printf("Before: \n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", A[i]);
    }

    /*1.冒泡排序*/
//    Bubble_Sort(A, 7);

    /* 2.插入排序 */
//    Insertion_Sort(A, 7);

    /* 3.希尔排序 */
//    int h[2] = {3, 1};
//    Shell_Sort(A, h, 7, 2);

    /*4.简单选择排序 */
    Selection_Sort(A, 7);

    /*5.堆排序 */
    // Heap_Sort(A,7);

    /*6.计数排序 */
    // int AA[7]={3,3,1,1,5,7,6};
    // Count_Sort(AA,7);

    /*7.归并排序 */
    // int TmpA[7];
    // M_Sort(A,TmpA,0,6);

    /*8.快速排序 */
    // Quick_Sort(A,0,6);

    printf("\nAfter: \n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}
