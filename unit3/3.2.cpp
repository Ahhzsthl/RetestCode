#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student{
    int score;
    int number;
    //第二种方法：定义大小关系
    bool operator< (Student student) const{
        if(score == student.score){
            //相同成绩的，学号小的在前
            return number < student.number;
        } else {
            //成绩低的排在前面
            return score < student.score;
        }
    }
};

Student arr[100];

// 第一种方法：设计比较函数
//bool Compare(Student x, Student y){
//    if(x.score == y.score){
//        return x.number < y.number;
//    }else{
//        return x.score < y.score;
//    }
//}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &arr[i].number, &arr[i].score);
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; ++i){
        printf("%d %d\n", arr[i].number, arr[i].score);
    }
    return 0;
}

