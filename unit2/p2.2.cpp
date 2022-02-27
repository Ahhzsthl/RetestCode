#include <iostream>
#include <cstdio>

int main(){
    //KY156
    int n;
    while(scanf("%d", &n) != EOF){
        int money = 3 * n;
        for(int x = 0; x <= 100; ++x){
            for(int y = 0; y <= 100 - x; ++y){
                //确定了其中两种鸡的数量时，第三种鸡的数量不需要枚举，用总数100直接减去既可以得到
                int z = 100 - x - y;
                if((x * 15 + y * 9 + z <= money) && (x + y + z == 100)){
                    printf("x=%d,y=%d,z=%d\n", x, y, z);
                }
            }
        }
    }
    return 0;
}
