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

void ConvertT2N(int number, int n){
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
    //十进制转换为N进制数
    int number;
    while(scanf("%d", &number) != EOF){
        ConvertT2N(number, 16);
    }
    return 0;
}
