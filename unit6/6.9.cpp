#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100;

struct Matrix{
    int row, col;
    int matrix[MAXN][MAXN];
    Matrix(){}
    Matrix(int r, int c) : row(r), col(c){};
};

Matrix add(Matrix x, Matrix y){
    Matrix answer = Matrix(x.row, x.col);
    for(int i = 0; i < answer.row; ++i){
        for(int j = 0; j < answer.col; ++j){
            answer.matrix[i][j] = x.matrix[i][j] + y.matrix[i][j];
        }
    }
    return answer;
}

Matrix multiply(Matrix x, Matrix y){
    Matrix answer = Matrix(x.row, y.col);
    for(int i = 0; i < answer.row; ++i){
        for(int j = 0; j < answer.col; ++j){
            answer.matrix[i][j] = 0;
            for(int k = 0; k < x.col; ++k){
                answer.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
            }
        }
    }
    return answer;
}

Matrix Transpose(Matrix x){
    Matrix answer = Matrix(x.col, x.row);
    for(int i = 0; i < x.row; ++i){
        for(int j = 0; j < x.col; ++j){
            answer.matrix[i][j] = x.matrix[j][i];
        }
    }
    return answer;
}

Matrix QuickPower(Matrix x, int n){
    Matrix answer = Matrix(x.row, x.col);
    for(int i = 0; i < answer.row; ++i){
        for(int j = 0; j < answer.col; ++j){
            if(i == j){
                answer.matrix[i][j] = 1;
            } else{
                answer.matrix[i][j] = 0;
            }
        }
    }
    //快速求幂的思想
    while(n != 0){
        if(n % 2 == 1){
            answer = multiply(answer, x);
        }
        n /= 2;
        x = multiply(x, x);
    }
    return answer;
}

void InputMatrix(Matrix& x){
    for(int i = 0; i < x.row; ++i){
        for(int j = 0; j < x.col; ++j){
            scanf("%d", &x.matrix[i][j]);
        }
    }
    return ;
}

void OutputMatrix(Matrix x){
    for(int i = 0; i < x.row; ++i){
        for(int j = 0; j < x.col; ++j) {
            if (j == 0) {
                printf("%d", x.matrix[i][j]);
            } else {
                printf(" %d", x.matrix[i][j]);
            }
        }
        printf("\n");
    }
    return ;
}

int main() {
    //矩阵
//    Matrix x = Matrix(2, 3);
//    Matrix y = Matrix(3, 2);
//    InputMatrix(x);
//    InputMatrix(y);
//    Matrix answer = multiply(x, y);
//    OutputMatrix(answer);
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF){
        Matrix x = Matrix(n, n);
        InputMatrix(x);
        Matrix answer = QuickPower(x, k);
        OutputMatrix(answer);
    }
    return 0;
}

