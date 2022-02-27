#include <iostream>
#include <cstdio>

using namespace std;

int dayTable[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool IsLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    //日期类型2：给出日期A和中间隔了多少天，计算日期B
    //打印日期
    int year, month, day;
    int number;
    while (scanf("%d %d", &year, &number) != EOF){
        month = 0;
        int row = IsLeapYear(year);
        while (number > dayTable[row][month]){
            number -= dayTable[row][month];
            month++;
        }
        day  = number;
        printf("%04d-%02d-%02d",year, month, day);
    }
    return 0;
}

