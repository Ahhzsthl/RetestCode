#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct Animal{
    int number;
    int order;
    //带参数的构造函数和不带参数的构造函数
    Animal(){}
    Animal(int n, int o) : number(n), order(o){}
};

queue<Animal> dogs;
queue<Animal> cats;

int main() {
    //Animal a; 等同于默认的不带参数的构造函数
//    Animal a = Animal();
//    Animal b = Animal(5, 0);
//    printf("%d %d \n", a.number, a.order);
//    printf("%d %d \n", b.number, b.order);

    int n;
    scanf("%d", &n);
    int order = 0;
    for(int i = 0; i < n; ++i){
        int event;
        scanf("%d", &event);
        if(event == 1){
            //动物进收容所
            int number;
            scanf("%d", &number);
            if(number > 0){
                dogs.push(Animal(number, order++));
            } else{
                cats.push(Animal(number, order++));
            }
        } else{
            //人领养动物
            int type;
            scanf("%d", &type);
            if(type == 0 && !dogs.empty() && !cats.empty()){
                if(dogs.front().order < cats.front().order){
                    printf("%d ", dogs.front().number);
                    dogs.pop();
                } else{
                    printf("%d ", cats.front().number);
                    cats.pop();
                }
            } else if(type == 0 && !dogs.empty() && cats.empty()){
                printf("%d ", dogs.front().number);
                dogs.pop();
            } else if(type == 0 && dogs.empty() && !cats.empty()){
                printf("%d ", cats.front().number);
                cats.pop();
            } else if(type == 1 && !dogs.empty()){
                printf("%d ", dogs.front().number);
                dogs.pop();
            } else if(type == 1 && !cats.empty()){
                printf("%d ", cats.front().number);
                cats.pop();
            }
        }
    }
    return 0;
}

