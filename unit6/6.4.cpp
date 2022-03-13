#include <iostream>
#include <cstdio>

using namespace std;

int GCD(int a, int b){
    //求解最大公约数
    if(b == 0){
        return a;
    } else{
        return GCD(b, a % b);
    }
}

int main() {
    //最大公约数和最小公倍数
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        printf("%d\n", GCD(a, b));    //最大公约数
        printf("%d\n", a * b / GCD(a, b));    //最小公倍数
    }
    return 0;
}

