#include <iostream>
#include <cstdio>

using namespace std;

int QuickPower(int x, int n){
    //当只求x的n次方的后三位时，后三位的结果只和每次的中间值的后三位有关
    int mod = 1000;
    int answer = 1;
    while(n != 0){
        if(n % 2 == 1){
            answer *= x;
            answer %= mod;  //只保留后三位
        }
        n /= 2;
        x *= x;
        x %= mod;   //只保留后三位
    }
}

int main() {
    //快速幂
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        if(a == 0 && b == 0){
            break;
        }
        printf("%d\n", QuickPower(a, b));
    }
    return 0;
}

