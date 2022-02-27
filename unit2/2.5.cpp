#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 80 + 10;

char matrix[MAXN][MAXN];

int main() {
    //叠框
    int n;
    char center;
    char outside;
    bool firstCase = true;
    while(scanf("%d %c %c", &n, &center, &outside) != EOF){
        if (firstCase){
            firstCase = false;
        }else{
            printf("\n");   //当是第一个输入时，不输出换行；不是第一个输出，则在输出的图形之前输出一个换行。实现在每次输出图形后输出换行的目的
        }
        for(int i = 0; i <= n/2; ++i){
            int j = n - 1 -i;   //(i, i)为每圈左上角的图标，(j ,j)为每圈右下角的图标
            int length = n - 2 * i;     //当前圈的边长
            char current;
            if ((n / 2 - i) % 2 == 0){
                current = center;
            }else{
                current = outside;
            }
            for (int k = 0; k < length; ++k) {
                 matrix[i][i + k] = current;    //上边赋值
                 matrix[i + k][i] = current;    //左边赋值
                 matrix[j][j - k] = current;    //右边赋值
                 matrix[j - k][j] = current;    //下边赋值
            }
        }
        if(n != 1){
            matrix[0][0] = ' ';     //抹去四个边角
            matrix[0][n-1] = ' ';
            matrix[n-1][0] = ' ';
            matrix[n-1][n-1] = ' ';
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

