#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<string, string> student;    //map容器

int main() {
    //散列表
    int n;
    scanf("%d", &n);
    getchar();
    while(n--){
        string str;
        getline(cin, str);
        int position = str.find(" ");
        string key = str.substr(0, position);   //输入字符串第一个空格之前的为学生编号
        student[key] = str;     //整个字符串的值为value
    }
    int m;
    scanf("%d", &m);
    while (m--){
        string key;
        cin >> key;
        map<string, string>::iterator it = student.find(key);   //迭代器进行遍历
        if(it != student.end()){
            cout << it->second << endl;
        } else{
            cout << "No Answer!" << endl;
        }
        //另一种查找方式
//        string answer = student[key];
//        if(answer == ""){     //当map没有找到对应的key时，会初始化默认的值，字符串会初始化为空，int会初始化为0，double会初始化为0.0
//            answer = "No Answer!";
//        }
//        cout << answer << endl;
    }
    return 0;
}

