#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 500 + 10;

vector<int> graph[MAXN];
int inDegree[MAXN];

vector<int> TopologicalSort(int n){
    vector<int> topology;   //拓扑排序的序列
    priority_queue<int, vector<int>, greater<int> > node;   //定义小根堆的优先队列：因为要求同样没有入度的情况下，编号小的结点优先级更高
    for (int i = 1; i <= n; ++i) {
        if(inDegree[i] == 0){
            node.push(i);
        }
    }
    while (!node.empty()){
        int u = node.top();
        node.pop();
        topology.push_back(u);      //优先队列头部的即为拓扑排序的下一个元素
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];    //依次删除和u相连的边，v和u相连，将v的入度减一
            inDegree[v]--;
            if(inDegree[v] == 0){
                node.push(v);   //入度为0时，压入优先队列
            }
        }
    }
    return topology;
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        memset(graph, 0, sizeof(graph));
        memset(inDegree, 0, sizeof(inDegree));
        while (m--){
            int from, to;
            scanf("%d%d", &from, &to);
            graph[from].push_back(to);  //记录from出去的边
            inDegree[to]++;   //入度加1
        }
        vector<int> answer = TopologicalSort(n);
        for (int i = 0; i < answer.size(); ++i) {
            if(i == 0){
                printf("%d", answer[i]);
            } else {
                printf(" %d", answer[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

