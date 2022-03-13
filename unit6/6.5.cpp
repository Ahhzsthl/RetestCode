#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool Judge(int n){
    //判断是否为质数
    if(n < 2){
        return false;
    }
    int bound = sqrt(n);    //判断质数是否能整除，最多只需要遍历到 根号n即可
    for(int i = 2; i <= bound; ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF){
        if(Judge(n)){
            printf("YES\n");
        } else{
            printf("NO\n");
        }
    }
    return 0;
}

