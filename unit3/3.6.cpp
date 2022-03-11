#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int arr[MAXN];

int Partition(int low, int high){
    int random = low + rand() % (high - low + 1);
    swap(arr[low], arr[random]);
    while(low < high){
        while(low < high && arr[low] <= arr[high]){
            high--;
        }
        swap(arr[low], arr[high]);
        while(low < high && arr[low] <= arr[high]){
            low++;
        }
        swap(arr[low], arr[high]);
    }
    return low;
}

int QuickSort(int low, int high, int p){
//    if(low < high){
//        int position = Partition(low, high);
//        QuickSort(low, position - 1);
//        QuickSort(position, high);
//    }
    //寻找第k大数：用快排的思想实现，时间复杂度为o(n)
    int position = Partition(low, high);
    if(position < p){
        return QuickSort(position + 1, high, p);
    }else if(position > p){
        return QuickSort(low, position-1, p);
    } else{
        return arr[p];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);
    int answer = QuickSort(0, n-1, n - k);
//    for(int i = 0; i < n; ++i){
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
    printf("%d", answer);
    return 0;
}

