#include <iostream>

using namespace std;

void setMatrix(int matrix[7][7]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> matrix[i][j];
        }
    }
}

int mainDiagonalF(int matrix[7][7]) {
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (i == j) sum += matrix[i][j];
        }
    }
    return sum;
}

int secundaryDiagonalF(int matrix[7][7]) {
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (i == j) sum += matrix[i][6 - j];
        }
    }
    return sum;
}

int main() {
    int matrix[7][7];
    int mainDiagonal, secundaryDiagonal;
    setMatrix(matrix);
    mainDiagonal = mainDiagonalF(matrix);
    secundaryDiagonal = secundaryDiagonalF(matrix);
    if (mainDiagonal > secundaryDiagonal) {
        cout << "MainDiagonal" << " " << mainDiagonal << endl;
    } else {
        cout << "SecundaryDiagonal" << " " << secundaryDiagonal << endl;
    }

    return 0;
}