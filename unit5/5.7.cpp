#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

int Priority(char c){   //判断运算符的优先级
    if(c == '#'){   //最左侧的运算符
        return 0;
    } else if (c == '$'){   //最右侧的运算符
        return 1;
    } else if( c == '+' || c == '-'){
        return 2;
    } else {
        return 3;
    }
}

double GetNumber(string str, int& index){   //在字符串中获得下个数字
    double number = 0;
    while(isdigit(str[index])){     //isdigit判断是否为十进制字符串
        number = number * 10 + str[index] - '0';
        index++;
    }
    return number;
}

double Calculate(double x, double y, char op){
    double result = 0;
    if(op == '+'){
        result = x + y;
    } else if (op == '-'){
        result = x - y;
    } else if (op == '*'){
        result = x * y;
    } else if (op == '/'){
        result = x / y;
    }
    return result;
}

int main() {
    //表达式求值
    string str;
    while(getline(cin, str)){
        if(str == "0"){
            break;
        }
        int index = 0;
        stack<char> operation;
        stack<double> number;
        operation.push('#');
        str += '$';
        while (index < str.size()){
            if(str[index] == ' '){
                index++;
            }else if(isdigit(str[index])){
                number.push(GetNumber(str, index));
            } else{
                if(Priority(str[index]) > Priority(operation.top())){
                    operation.push(str[index]);
                    index++;
                } else{
                    double y = number.top();
                    number.pop();
                    double x = number.top();
                    number.pop();
                    char op = operation.top();
                    number.push(Calculate(x, y, op));
                    operation.pop();
                }
            }
        }
        printf("%.2f\n", number.top());
    }
    return 0;
}

