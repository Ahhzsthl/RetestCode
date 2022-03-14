#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100;

int arrFibonacci[MAXN];

int Fibonacci(int n){
    if(n == 1 || n == 0){
        return 1;
    } else {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

void Initial(){
    //时间复杂度为o(n)
    arrFibonacci[0] = 1;
    arrFibonacci[1] = 1;
    for(int i = 2; i < MAXN; ++i){
        arrFibonacci[i] = arrFibonacci[i - 1] + arrFibonacci[i - 2];
    }
    return ;
}

//用矩阵快速幂时间复杂度为O(log n)

int main() {
    int n;
    Initial();
    while (scanf("%d", &n) != EOF){
        printf("%d\n", Fibonacci(n));
        printf("%d\n", arrFibonacci[n]);
    }
    return 0;
}

