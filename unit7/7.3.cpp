#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int length[MAXN];

int main() {
    //物品放入箱子问题，每个箱子最多放两个物品，每个箱子最多可放长度为l的物品
    int n, l;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &length[i]);
    }
    sort(length, length + n);
    int left = 0;
    int right = n - 1;
    int answer = 0;
    while(left < right){
        if(length[left] + length[right] < l){
            right--;
            left++;
        } else{
            right--;
        }
        answer++;
    }
    printf("%d\n", answer);
    return 0;
}

