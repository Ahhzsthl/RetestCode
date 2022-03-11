#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000 + 10;

int arr[MAXN];
int temp[MAXN];
int number;

void Combine(int left, int middle, int right){
    int i = left, j = middle + 1;
    int k = left;
    while(i <= middle && j <= right){   //注意=
        if(arr[i] <= arr[j]){   //注意=
            temp[k++] = arr[i++];
        }else{
            number += middle + 1 - i;
            temp[k++] = arr[j++];
        }
    }
    while (i <= middle){
        temp[k++] = arr[i++];
    }
    while (j <= right){
        temp[k++] = arr[j++];
    }
    for (k = left; k <= right; ++k) {   //注意=
        arr[k] = temp[k];
    }
}

void MergeSort(int left, int right){
    //归并排序
    if(left < right){
        int middle = left + (right - left) / 2;   //这样写，保证当left和right比较接近int的表示范围时不会发生溢出
        MergeSort(left, middle);
        MergeSort(middle + 1, right);
        Combine(left, middle, right);
    }
}

int main() {
    //用归并排序求解逆序数
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int caseOrder = 0; caseOrder <= caseNumber; ++caseOrder){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", &arr[i]);
        }
        number = 0;
        MergeSort(0, n - 1);    //自己写的排序是两边都可以取到，闭区间
//        for(int i = 0; i < n; ++i){
//            printf("%d ", arr[i]);
//        }
//        printf("\n");
        printf("Scenario #%d:\n", caseOrder);
        printf("%d\n\n", number);
    }
    return 0;
}

