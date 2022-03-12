#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main() {
    //栈及其基本操作
    stack<int> myStack;
    for(int i = 0; i < 10; ++i){
        myStack.push(i);
    }
    int sum = 0;
    while(!myStack.empty()){
        printf("%d ", myStack.top());
        sum += myStack.top();
        myStack.pop();
    }
    printf("\n%d\n", sum);

    return 0;
}

