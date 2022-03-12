#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    //字符串的遍历：对数字的每个位上的值进行运算的时候要进行取模处理，若转化为字符串的话，需要变为对每一个字符的操作
    string str1, str2;
    while(cin >> str1 >> str2){
        int answer = 0;
        for(int i = 0; i < str1.size(); ++i){
            for(int j = 0; j < str2.size(); ++j){
                answer += (str1[i] - '0') * (str2[j] - '0');
                //在用字符串进行输出的时候，输出的是对应的ascII码值，将其转变为正确的数字可以减去字符0来实现
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}

