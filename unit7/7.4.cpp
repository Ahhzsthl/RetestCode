#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int arr[MAXN];

bool Judge(int n, int m, int distance){
    //n个间隔，m头牛，距离为distance
    int current = arr[0];   //当前的牛放到了哪个房间里面
    int number = 1;  //记录放了多少头牛
    for(int i = 0; i < n; ++i){
        if(arr[i] - current >= distance){
            number ++;
            current = arr[i];
        }
        if(number > m){
            return true;
        }
    }
    return false;
}

int main() {
    //疯牛问题，最大的最小问题，求不同牛之间的最小间距的最大值
    //最大值问题 —————— 判定性问题，用二分策略求解
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        for(int i = 0; i < n; ++i){
            scanf("%d", arr[i]);
        }
        sort(arr, arr + n);
        int left = 1;   //牛不能在同一个栅栏内，最小距离为1
        int right = arr[n - 1] - arr[0];    //最远的距离为起始栅栏和终止栅栏之间的距离
        while (left <= right){
            int middle = left + (right - left) / 2;
            if(Judge(n, m, middle)){
                left = middle + 1;      //求的是最大值，所以将左端点的值增大
            } else{
                right = middle - 1;
            }
        }
        printf("%d\n", right);
    }

    return 0;
}

