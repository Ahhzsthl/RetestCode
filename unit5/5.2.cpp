#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    //队列及其基本操作
    queue<int> myQueue;
    for(int i = 0; i < 10; ++i){
        myQueue.push(i);
    }
    int sum = 0;
    while(!myQueue.empty()){
        sum += myQueue.front();
        myQueue.pop();
    }
    printf("%d\n", sum);

    return 0;
}

