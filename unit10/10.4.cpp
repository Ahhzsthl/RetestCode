#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    //利用优先队列构造哈夫曼树
    //priority_queue<Complex> myPriorityQueue;    //优先队列默认定义为大根堆，即输出权值大的节点
    //priority_queue<int, vector<int>, less<int> > myPriorityQueue;    //等同于上一种定义方式
    int n;
    while(scanf("%d", &n) != EOF){
        //最后一个>前必须要有空格，否则会被认为是右移运算符
        priority_queue<int, vector<int>, greater<int> > myPriorityQueue;    //定义为小根堆的优先队列
        while (n--){
            int x;
            scanf("%d", &x);
            myPriorityQueue.push(x);
        }
        int answer = 0;
        while(myPriorityQueue.size() > 1){
            int a = myPriorityQueue.top();
            myPriorityQueue.pop();
            int b = myPriorityQueue.top();
            myPriorityQueue.pop();
            answer += a + b;
            myPriorityQueue.push(a + b);
        }
        printf("%d", answer);
    }

    return 0;
}

