#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    //KY50
    int n;
    while(scanf("%d", &n) != EOF){
        int number = 0;
        for(int i = 0; i <= n; ++i){
            if(!(i % 7 == 0 || i / 10 == 7 || i % 10 == 7)){
                number += i * i;
            }
        }
        printf("%d\n", number);
    }

    return 0;
}

