#include <iostream>
#include <cstdio>

using namespace std;

int Reverse(int number){
    int reverseNumber = 0;
    while(number!=0){
        reverseNumber *= 10;
        reverseNumber += number % 10;
        number /= 10;
    }
    return reverseNumber;
}

int main() {
    //完全平方数
    for (int i = 0; i <= 256; ++i) {
        if(i * i == Reverse(i * i)){
            printf("%d\n", i);
        }
    }
    return 0;
}

