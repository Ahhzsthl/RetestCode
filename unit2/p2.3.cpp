#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    //KY95
    int n = 0;
    while(scanf("%d", &n) != EOF){
        bool flag = false;
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        //枚举的时候，若要求输出最大或者最小的结果，可以考虑变换枚举的顺序，来达到第一次输出即为所需的目的
        for(int i = 9; i >= 1; --i){
            for(int j = 9; j >= 0; --j){
                int total = i * 10000 + x * 1000 + y * 100 + z * 10 + j;
                if(total % n == 0){
                    int perPrice = total / n;
                    printf("%d %d %d\n", i, j, perPrice);
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            printf("%d\n", 0);
        }
    }
    return 0;
}

