#include <iostream>
#include <cstdio>

using namespace std;

long long Hanoi(int n){
    //汉诺塔问题
    if(n == 1){
        return 1;
    } else {
        return  2 * Hanoi(n - 1) + 1;
    }
}

int main() {
    //汉诺塔
    return 0;
}

