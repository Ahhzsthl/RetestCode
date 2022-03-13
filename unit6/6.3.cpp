#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

char Int2Char(int target){
    if(target < 10){
        return target + '0';
    } else {
        return target - 10 + 'A';   //进行十以上进制的转换时，余数会大于10，要转换为对应的 A-Z 字符处理
    }
}

int Char2Int(char target){
    if('0' <= target && target <= '9'){
        return target - '0';
    } else{
        return target - 'A' + 10;
    }
}

long long ConvertM2T(string str, int m){
    long long number = 0;
    for(int i = 0; i < str.size(); ++i){
        number *= m;
        number += Char2Int(str[i]);
    }
    return number;
}

void ConvertT2N(long long number, int n){
    vector<char> answer;    //用向量进行存储转换的结果
    if(number == 0){
        answer.push_back('0');
    } else {
        while (number != 0) {
            answer.push_back(Int2Char(number % n));
            number /= n;
        }
    }
    for(int i = answer.size() - 1; i >= 0; --i){
        printf("%c", answer[i]);
    }
    printf("\n");
}

int main() {
    //M进制转换为N进制的通用代码
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF){
        string str;
        cin >> str;
        long long number = ConvertM2T(str, m);
        ConvertT2N(number, n);
    }
    return 0;
}

