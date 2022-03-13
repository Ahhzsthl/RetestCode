#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 4e4;

bool isPrime[MAXN];
vector<int> prime;

void Initial(){
    //质数筛法
    for(int i = 0; i < MAXN; i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i < MAXN; ++i){
        if(!isPrime[i]){
            continue;
        }
        prime.push_back(i);
        if(i > MAXN / i){
            continue;   //i*i可能会超出表示范围，用这种方法可以防止越界
        }
        for(int j = i * i; j < MAXN; j += i){
            isPrime[j] = false;
        }
    }
}

int NumberOfPrimeFactors(int number){
    //求质因子
    //质因子：1.所有的质因子全部都小于根号n 2.有n-1个小于根号n的质因子，有且仅有一个大于根号n的质因子（若有两个大于根号n的质因子，就会超出n）
    //
    int answer = 0;
    for(int i = 0; i < prime.size(); ++i){
        int factor = prime[i];
        if(number < factor){
            break;
        }
        int exponent = 0;
        while(number % factor == 0){
            exponent++;
            number = number / factor;
        }
        answer += exponent;
    }
    if(number > 1){
        answer += 1;    //有一个大于根号n的质因子
    }
    return answer;
}

int NumberOfPFactors(int number){
    //求约数
    int answer = 1;
    for(int i = 0; i < prime.size(); ++i){
        int factor = prime[i];
        if(number < factor){
            break;
        }
        int exponent = 0;
        while(number % factor == 0){
            exponent++;
            number = number / factor;
        }
        answer *= exponent;
    }
    if(number > 1){
        answer *= 2;
    }
    return answer;
}

int main() {
    Initial();
    int number;
    while(scanf("%d", &number) != EOF){
        printf("%d\n", NumberOfPrimeFactors(number));
    }
    return 0;
}

