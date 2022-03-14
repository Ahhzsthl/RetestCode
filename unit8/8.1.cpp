#include <iostream>
#include <cstdio>

using namespace std;

long long Factorial(int n){
    //n的阶乘
    if(n == 0){
        return 1;
    } else {
        return n * Factorial(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", Factorial(n));
    return 0;
}
