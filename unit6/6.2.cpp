#include <iostream>
#include <cstdio>

using namespace std;

int Char2Int(char target){
    if('0' <= target && target <= '9'){
        return target - '0';
    } else{
        return target - 'A' + 10;
    }
}

void ConvertM2T(string str, int m){
    int number = 0;
    for(int i = 0; i < str.size(); ++i){
        number *= m;
        number += Char2Int(str[i]);
    }
    printf("%d\n", number);
}

int main() {
    //N进制转换为10进制
    string str;
    while (cin >> str){
        str = str.substr(2);
        ConvertM2T(str, 16);
    }
    return 0;
}

