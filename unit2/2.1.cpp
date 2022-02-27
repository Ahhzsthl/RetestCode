#include <iostream>
#include <cstdio>

int main() {
    //1.单组输入
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
    //2.多组输入,未知组数
    while(scanf("%d %d", &a, &b)!= EOF){
        printf("%d\n", a+b);
    }
    //3.多组输入，指定组数
    int n;
    scanf("%d", &n);
    while(n--){
        int a1, b1;
        scanf("%d %d",&a1, &b1);
        printf("%d\n", a1+b1);
    }
    //4.多组输入，特定跳出
    while(scanf("%d %d", &a, &b)!=EOF){
        if(a==0 && b==0){
            break;
        }
        printf("%d\n", a+b);
    }
    return 0;
}
