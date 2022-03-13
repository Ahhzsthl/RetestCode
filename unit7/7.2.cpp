#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000 + 10;

long long gun[MAXN];
long long monster[MAXN];

bool Compare(long long x, long long y){
    return x > y;
}

int main() {
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber--){
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &gun[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%lld", &monster[i]);
        }
        sort(gun, gun + n, Compare);
        sort(monster, monster + m);
        //每次用伤害最高的枪打防御最低的怪
        long long answer = 0;
        for(int j = 0; j < n; ++j){
            if(j > m || gun[j] <= monster[j]){
                break;
            }
            answer += gun[j] - monster[j];
        }
        printf("%lld\n", answer);
    }
    return 0;
}

