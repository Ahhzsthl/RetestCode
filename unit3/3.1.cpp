#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int arr[MAXN];

int main(){
    //Key 210
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i){
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        for(int i = 0; i < n; ++i){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}