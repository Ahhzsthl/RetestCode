#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 10;

bool visit[MAXN];
char sequence[MAXN];

void GetPermutation(string str, int index){
    //全排列
    if(index == str.size()){
        for(int i = 0; i < str.size(); ++i){
            printf("%c", sequence[i]);
        }
        printf("\n");
    }
    for(int i = 0; i < str.size(); ++i){
        if(visit[i]){
            continue;
        }
        visit[i] = true;
        sequence[index] = str[i];   //把当前的字符放入sequence
        GetPermutation(str, index + 1);
        visit[i] = false;
    }
}

int main() {
    string str;
    while(cin >> str){
        sort(str.begin(), str.end());
        GetPermutation(str, 0);
        printf("\n");
    }
    return 0;
}

