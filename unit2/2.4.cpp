#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    //输出梯形
    //输入一个高度为h,输出一个高为h，上底边为h的梯形
    int h;
    while(scanf("%d", &h) != EOF){
        int row = h;
        int col = h + 2 * (h - 1);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (j < col - (h + 2*i)){
                    printf(" ");
                }else{
                    printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}

