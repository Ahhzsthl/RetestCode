#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int main() {
    //括号匹配
    string str;
    while(cin >> str){
        stack<int> brackets;
        string answer(str.size(), ' ');
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == '('){
                brackets.push(i);
            } else if(str[i] == ')'){
                if(!brackets.empty()){
                    brackets.pop();
                } else{
                    answer[i] = '?';
                }
            }
        }
        while (!brackets.empty()){
            answer[brackets.top()] = '$';
            brackets.pop();
        }
        cout << str << endl;
        cout << answer << endl;
    }
    return 0;
}

