#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Program{
    int statTime;
    int endTime;
};

Program arr[MAXN];

bool Compare(Program x, Program y){
    return x.endTime < y.endTime;
}

int main() {
    //区间贪心:看电视，在所有的节目中求出最多能看完多少节目
    //每次看节目不能中断，必须全部看完； 最优解相当于是按照结束时间进行排序，依次求出
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0){
            break;
        }
        for(int i = 0; i < n; ++i){
            scanf("%d %d", &arr[i].statTime, &arr[i].endTime);
        }
        sort(arr, arr + n, Compare);
        int current = 0;
        int answer = 0;
        for(int i = 0; i < n; ++i){
            if(current <= arr[i].statTime){
                answer++;
                current = arr[i].endTime;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}

