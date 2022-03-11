#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10];

bool Compare(int x, int y){
    /* 比较函数的原理： comp定义了在升序排序中第一个参数是否应该排在第二个参数之前
        若comp返回true，则第一个参数小于第二个参数，将第一个参数排在第二个参数之前
        若comp返回false，则第一个参数大于第二个参数，将第一个参数排在第二个参数之后
     */
    if(x % 2 == 1 && y % 2 == 1){
        //奇数按照从大到小排序
        return x > y;
    } else if(x % 2 == 0 && y % 2 == 0){
        //偶数按照从小到大排序
        return x < y;
    } else if(x % 2 == 1 && y % 2 == 0){
        //奇数排在偶数前面
        return true;
    } else{
        return false;
    }
    //最后两种情况可以优化为这样
//    else{
//        return x % 2 > y % 2;
//    }
}

int main() {
    while (scanf("%d", &arr[0]) != EOF){
        for(int i = 1; i < 10; ++i){
            scanf("%d", arr[i]);
        }
        sort(arr, arr + 10, Compare);
        for(int i = 0; i < 10; ++i){
            printf("%d", arr[i]);
        }
    }
    return 0;
}

