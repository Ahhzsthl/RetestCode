#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    //字符加密
    string str;
    while(getline(cin, str)){
        //多组输入，特例跳出
        //getline 可以获得一行的输入信息 cin获得的字符串在遇到空格后会停止
        if(str == "ENDOFINPUT"){
            break;
        }
        getline(cin,str);
        for(int i = 0; i < str.size(); ++i){
            if('A' <= str[i] && str[i] <= 'Z'){
                str[i] = (str[i] - 'A' - 5 + 26) % 26 + 'A';
            }
        }
        cout << str << endl;
        getline(cin, str);
    }
    return 0;
}

