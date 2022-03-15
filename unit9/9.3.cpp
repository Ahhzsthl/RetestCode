#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int direction[8][2] = {
        {-1, -2}, {1, -2}, {-2, -1}, {2, -1},
        {-2, 1}, {2, 1}, {-1, 2}, {1, 2}
};

const int MAXN = 10;

bool visit[MAXN][MAXN];

bool DFS(int x, int y, int step, string answer, int p, int q){
    if(step == p * q){
        cout << answer << endl << endl;
        return true;
    }
    for(int i = 0; i < 8; ++i){
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];
        if(nx < 0 || nx >= p || ny < 0 || ny >= q || visit[nx][ny]){
            continue;
        }
        visit[nx][ny] = true;
        char col = ny + 'A';
        char row = nx + '1';
        if(DFS(nx, ny, step + 1, answer + col + row, p, q)){
            return true;
        }
        visit[nx][ny] = false;
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    int caseNumber = 0;
    while(n--){
        int p, q;
        scanf("%d %d", &p, &q);
        memset(visit, false, sizeof(visit));
        cout << "Scenario #" << ++caseNumber << ":" << endl;
        visit[0][0] = true;
        if(DFS(0, 0, 1, "A1", p, q)){
            continue;
        } else{
            cout << "impossible" << endl << endl;
        }
    }
    return 0;
}
