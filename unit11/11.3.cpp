#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 200;
const int INF = INT_MAX;

struct Edge{
    int to;
    int length;
    Edge(int t, int l): to(t), length(l) {}
};

vector<Edge> graph[MAXN];   //图定义为向量，用向量的下标表示图的from顶点，图的边中只定义to的顶点和长度
int dis[MAXN];      //记录从起始顶点到目标顶点之间的距离
bool visit[MAXN];       //false:未加入最短路径的顶点为集合T， true:已加入最短路径的顶点集合为S

void Dijkstra(int start, int n){
    memset(visit, false, sizeof(visit));    //访问数组均设为false
    fill(dis, dis + n, INF);    //初始化距离为无穷大
    dis[start] = 0;     //从起点到起点本身为0
    for (int i = 0; i < n; ++i) {
        //对所有的顶点进行遍历
        int u = -1;
        //找到当前集合T中距离最小的一个顶点
        for (int j = 0; j < n; ++j) {
            if(visit[j]){
                continue;
            }
            if(dis[u] > dis[j] || u == -1){
                u = j;
            }
        }
        for (int j = 0; j < graph[u].size(); ++j) {
            //遍历顶点U相连的边
            int v = graph[u][j].to;
            int d = graph[u][j].length;
            if(dis[u] + d < dis[v]){        //起始顶点经过u到v的路径长度 小于 起始顶点到V的路径长度
                dis[v] = dis[u] + d;
            }
        }
        visit[u] = true;
    }
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF){
        memset(graph, 0, sizeof(graph));
        while (m--){
            int from, to, length;
            scanf("%d%d%d", &from, &to, &length);
            //无向图 要同时产生两条边
            graph[from].push_back(Edge(to, length));
            graph[to].push_back(Edge(from, length));
        }
        int start;
        int terminal;
        scanf("%d%d", &start, &terminal);
        Dijkstra(start, n);
        if(dis[terminal] == INF){
            dis[terminal] = -1;
        }
        printf("%d", dis[terminal]);
    }
    return 0;
}

