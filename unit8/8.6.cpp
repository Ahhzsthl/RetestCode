#include <iostream>
#include <cstdio>

using namespace std;

int CountNodes(int m, int n){
    if(m > n){
        return 0;
    } else {
        return CountNodes(2 * m, n) + CountNodes(2 * m + 1, n) + 1;
    }
}

int main() {
    //求二叉树节点m所在子树中包括的节点的数目
    //特殊二叉树最多有n个节点
    int n, m;
    while(scanf("%d %d", &m, &n) != EOF){
        printf("%d\n", CountNodes(m,n));
    }
    return 0;
}

