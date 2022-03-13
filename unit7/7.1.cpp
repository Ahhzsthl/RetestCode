#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100;

struct JavaBean{
    double weight;
    double cost;
};

JavaBean arr[MAXN];

bool Compare(JavaBean x, JavaBean y){
    return x.cost / x.weight > y.cost / y.weight;
}

int main() {
    int n, m;
    //简单贪心策略
    while(scanf("%d %d", &n, &m) != EOF){
        if(n == -1 && m == -1){
            break;
        }
        for(int i = 0; i < n; ++i){
            scanf("%lf %lf", &arr[i].weight, &arr[i].cost);
        }
        sort(arr, arr + n, Compare);
        double answer = 0;
        for(int i = 0; i < n; ++i){
            if(m >= arr[i].cost){
                answer += arr[i].weight;
                m -= arr[i].cost;
            } else {
                answer += (m / arr[i].cost) * arr[i].weight;
                m = 0;
                break;
            }
        }
        printf(".3f\n", answer);
    }
    return 0;
}
