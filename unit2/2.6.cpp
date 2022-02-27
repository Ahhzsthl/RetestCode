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
    //日期类型1：给出日期A和日期B，计算中间隔了多少天
    //输入年月日，计算该天是本年的第几天
    int year, month, day;
    while (scanf("%d %d %d", &year, &month, &day)){
        int number = 0;
        int row = IsLeapYear(year); //判断出来闰年 恰好对应dayTable中的行数
        for (int i = 0; i < month; ++i) {
            number += dayTable[row][i];
        }
        number += day;
        printf("%d\n", number);
    }
    return 0;
}

