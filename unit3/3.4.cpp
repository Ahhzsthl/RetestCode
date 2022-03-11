#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAIN = 1e6 + 10;
const int RANGE = 5e5;

int arr[MAIN];
int count[MAIN];

int main() {
    //计数排序： 在限制数组内数据出现范围的条件下，可以通过O(n)的复杂度求出来
    int m, n;
    while(scanf("%d %d", &n, &m) != EOF){
        //将计数数组清空 在cstring这个头文件
        memset(count, 0, sizeof(count));
        for(int i = 0; i < n; ++i){
            scanf("%d", &arr[i]);
            count[arr[i] + RANGE] ++;
        }
        int index = 0;
        for(int i = 0; i < MAIN; ++i){
            while(count[i]--){
                arr[index++] = i - RANGE;
            }
        }
        for(int i = n - 1; i >= n - m; --i){
            if(i == n - m){
                printf("%d\n", arr[i]);
            }else{
                printf("%d ", arr[i]);
            }
        }
    }
    return 0;
}

