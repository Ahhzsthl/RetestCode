#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    //字符串定义
    string s = "hello world";
    string s1;
    string s2 = s;
    string s3(s);
    string s4(s, 6);
    string s5(s, 0, 5);
    cout << "define string" << endl;
    cout << s << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;

    //字符串插入 删除
    s1.insert(0, "hello world");
    cout << s1 << endl;
    s1.insert(6, s);
    cout << s1 << endl;
    s1.erase(12);
    cout << s1 << endl;
    s1.erase(0, 6);
    cout << s1 << endl;

    //字符串比较
    s1 = "ab";
    s2 = "abc";
    s3 = "bbc";
    s4 = s1 + s2;
    cout << s4 << endl;
    cout << (s1 <= s2) << endl;     //按照字符的大小进行比较
    cout << (s1 <= s3) << endl;

    //查找字符位置，截断字符
    int pos1 = s4.find("ab");
    cout << pos1 << endl;
    int pos2 = s4.find("ab", 2);
    cout << pos2 << endl;
    s1 = s4.substr(3);
    s2 = s4.substr(0, 2);
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}
