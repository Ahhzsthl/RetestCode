#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<long long> sequence;

int main() {
    //逆序输出
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i){
            long long number;
            scanf("%lld", number);
            sequence.push(number);
        }
        while(!sequence.empty()){
            printf("%lld", sequence.top());
            sequence.pop();
        }
        printf("\n");
    }
    return 0;
}

