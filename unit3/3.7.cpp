#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int arr[MAXN];
int hashTable[MAXN];

bool LinearSearch(int n, int target){
    for(int i = 0; i < n; ++i){
        if(arr[i] == target){
            return true;
        }
    }
    return false;
}

bool BinarySearch(int left, int right, int target){
    while(left <= right){
        int middle = left + (right - left) / 2;
        if(arr[middle] > target){
            right = middle - 1;
        }else if(arr[middle] < target){
            left = middle + 1;
        } else{
            return true;
        }
    }
    return false;
}

int main() {
    //线性查找 和 二分查找
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
        hashTable[arr[i]] = true;     //hash查找
    }
    sort(arr, arr + n);
    int m;
    scanf("%d", &m);
    while (m--){
        int target;
        scanf("%d", &target);
        if(hashTable[target]){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

