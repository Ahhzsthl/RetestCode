#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1e5 + 10;

int water[MAXN];

bool Judge(int n, int k, int time){
    //烘干机每分钟可以烘干k的水分，有n件衣服，完成时间为time
    int sum = 0;
    for(int i = 0; i < n; ++i){
         if(water[i] > time){
             sum += ceil((water[i] - time) * 1.0 / (k - 1));    //每分钟会自己烘干1，所以是除以k-1
             //ceil向上取整 只能对浮点数进行处理，乘上1.0变为浮点数
         }
         if(sum > time){
             return false;
         }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &water[i]);
    }
    int k;
    scanf("%d", &k);    //烘干机每分钟烘干k
    sort(water, water + n);
    if(k == 1){
        printf("%d\n", water[n - 1]);
    } else{
        int left = 1;
        int right = water[n - 1];   //最大的衣服自然风干时，为右边界
        while(left < right){
            int middle = left + (right - left) / 2;
            if(Judge(n, k, middle)){
                right = middle - 1;     //求最小时间，所以满足情况时，将右端点缩小
            } else {
                left = middle + 1;
            }
        }
        printf("%d\n", left);
    }
    return 0;
}

