#include <iostream>
using namespace std;

int N, r, c;
int result;
int startR, endR;
int startC, endC;
int value = 0;
int range = 1;
int area = 1;

void findZ(int num, int row, int col) {
    if (num <= 0) {
        return;
    }

    int a = 0;
    int midR = (startR + endR) / 2;
    if (midR < col) {
        startR = midR + 1;
        a = 1;
    } else {
        endR = midR;
    }

    int b = 0;
    int midC = (startC + endC) / 2;
    if (midC < row) {
        startC = midC + 1;
        b = 2;
    } else {
        endC = midC;
    }
    value += a * area + b * area;
    area /= 4;
    range /= 2;
    findZ(num - 1, row, col);
}

int main(void) {
    cin >> N >> r >> c;

    for (int i = 0; i < N; i++) {
        range *= 2;
    }
    endR = range - 1;
    endC = range - 1;
    for (int i = 0; i < N - 1; i++) {
        area *= 4;
    }

    findZ(N, r, c);
    cout << value << '\n';
    return 0;
}