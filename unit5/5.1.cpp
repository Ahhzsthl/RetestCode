#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    //向量的使用:向量的存储空间会在不够时翻倍，向量插入和删除的平均时间复杂度为O(1)
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> myVector1;
    vector<int> myVector2(arr, arr + 5);    //可以用数组名来代表数组的首地址
    vector<int> myVector3(5, 2);
    vector<int> myVector4(myVector2);
    vector<int> myVector5(myVector4.begin(), myVector4.begin() + 3);    //myVector4的首地址

    int n = myVector2.size();
    myVector2.pop_back();
    myVector2.push_back(6);
    myVector2.insert(myVector2.begin() + 3, 5);
    myVector2.insert(myVector2.begin() + 3, 5, 0);
    myVector2.insert(myVector2.begin() + 3, arr, arr + 2);
    myVector2.erase(myVector2.begin() + 5);
    myVector2.erase(myVector2.begin() + 1, myVector2.begin() + 3);
    myVector2.clear();

    return 0;
}
