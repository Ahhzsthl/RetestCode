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
    //反序数
    for (int i = 1000; i <= 9999; ++i) {
        if(i * 9 == Reverse(i)){
            printf("%d\n", i);
        }
    }
    return 0;
}
