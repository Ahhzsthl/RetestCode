#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1000;

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

int main() {
    Initial();
    int k;
    while(scanf("%d", &k) != EOF){
        printf("%d\n", prime[k - 1]);
    }
    return 0;
}

