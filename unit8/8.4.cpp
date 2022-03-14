#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

bool GetNextPermutation(string& str){
    int n = str.size();
    int index = n - 2;  //找到一个下降的局部
    while(index >= 0 && str[index] >= str[index + 1]){
        index--;    //找到最长的降序的局部
    }
    if(index < 0){
        return false;   //已经是从大到小排列了，没有下一个全排列
    }
    for(int i = n - 1; i > index; --i){
        if(str[i] > str[index]){
            //从后往前，找到最小的大于新加入元素的位置
            swap(str[index], str[i]);
            break;
        }
    }
    reverse(str.begin() + index + 1, str.end());    //把后面
    return true;
}

int main() {
    string str;
    while(cin >> str){
        sort(str.begin(), str.end());
        do {
            cout << str << endl;
        } while (GetNextPermutation(str));
        cout << endl;
    }
    //next_permutation(str.begin(), str.end());     //C++内部实现方式
    return 0;
}

