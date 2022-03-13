#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1000 +10;

struct Interval{
    double left;
    double right;
};

Interval arr[MAXN];

bool Compare(Interval x, Interval y){
    return x.left < y.left;     //区间左端点小的在前
}

int main() {
    int n, d;
    int caseNumber = 0;
    while(scanf("%d %d", &n, &d) != EOF){
        if(n == 0 && d == 0){
            break;
        }
        bool flag = true;
        for(int i = 0; i < n; ++i){
            int x, y;
            scanf("%d %d", &x, &y);
            if(y > d){
                flag = false;
            } else {
                arr[i].left = x - sqrt(d * d - y * y * 1.0);
                arr[i].right = x + sqrt(d * d - y * y * 1.0);       //记录海上的点在海岸线上能建设雷达的区间
            }
        }
        if(!flag){
            printf("Case %d: %d\n", ++caseNumber, -1);
        }else{
            sort(arr, arr + n, Compare);
            double current = arr[0].right;
            int answer = 1;
            for(int i = 0; i < n; ++i){
                if(arr[i].left <= current){
                    current = min(current, arr[i].right);       //更新为最新加入的区间的右端点
                } else {
                    current = arr[i].right;
                    answer++;
                }
            }
            printf("Case %d: %d\n", ++caseNumber, answer);
        }
    }
    return 0;
}

