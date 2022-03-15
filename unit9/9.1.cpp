#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 10;

struct status{
    //1.状态空间
    int position;
    int time;
    status(){};
    status(int p, int t) : position(p), time(t) {};
};

bool visit[MAXN];

int BFS(int n, int k){
    //人的位置为n,牛的位置为k
    queue<status> myQueue;
    status start = status(n, 0);    //3.起始态
    myQueue.push(start);
    visit[n] = true;    //初始状态入队，标记已被访问过
    while(!myQueue.empty()){
        status current = myQueue.front();
        if(current.position == k){      //4.终止态
            return current.time;    //已经找到牛时，返回当前所花费的时间
        }
        myQueue.pop();  //将队头出队
        for(int i = 0; i < 3; ++i){
            //2.状态转移
            //有三种转移状态   依次判断，若三种状态合法就将其入队
            status next = current;
            if(i == 0){
                next.position -= 1;
            } else if (i == 1){
                next.position += 1;
            } else {
                next.position *= 2;
            }
            next.time += 1;
            if(next.position < 0 || next.position > 1e5 || visit[next.position]){
                //超出表示范围 或者 该节点已经被访问过 则跳过该节点，不用将其入队
                continue;
            }
            myQueue.push(next);
            visit[next.position] = true;
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    memset(visit, false, sizeof(visit));
    printf("%d\n", BFS(n, k));
    return 0;
}
