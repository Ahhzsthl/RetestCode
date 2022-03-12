#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXM = 100;

int nextTable[MAXM];

void GetNextTable(string pattern){
    int m = pattern.size();
    int j = 0;
    nextTable[j] = -1;
    int t = nextTable[j];
    while(j < m){
        if(t == -1 || pattern[j] == pattern[t]){
            t++;
            j++;
            nextTable[j] = t;   //nextTable[j + 1] = nextTable[j] + 1
         } else{
            t = nextTable[t];
        }
    }
}

int KMP(string text, string pattern){
    GetNextTable(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = 0;
    int j = 0;
    while (i < n && j < m){
        if(j == -1 || text[i] == pattern[j]){
            i++;
            j++;
        } else{
            j = nextTable[j];
        }
    }
    if(j == m){
        return i - j;
    }else{
        return -1;
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    int position = KMP(text, pattern);
    cout << position << endl;
    return 0;
}

