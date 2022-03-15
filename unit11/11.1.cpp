#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000;

int father[MAXN];
int height[MAXN];

void Initial(int n){
    for (int i = 0; i <= n; ++i) {
        father[i] = i;
        height[i] = 0;
    }
}

int Find(int x){
    if(x != father[x]){
        father[x] = Find(father[x]);    //路径压缩
    }
    return father[x];
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x != y){
        //矮树连接到高树
        if(height[x] < height[y]){
            father[x] = y;
        } else if(height[y] < height[x]){
            father[y] = x;
        } else{
            father[y] = x;
            height[x]++;
        }
    }
}

int main() {
    //并查集判断是否为连通图
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        if(n == 0 && m == 0){
            break;
        }
        Initial(n);
        while(m--){
            int x, y;
            scanf("%d %d", &x, &y);
            Union(x, y);
        }
        int component = 0;
        for(int i = 1; i <= n; ++i){    //顶点的编号是从1开始的
            if(i == Find(i)){
                component++;
            }
        }
        if(component == 1){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
