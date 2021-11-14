#include <bits/stdc++.h>
using namespace std;

int row, col;
int green, red;

// 0: 호수, 1: 배양액을 뿌릴 수 없는 땅, 2: 배양액을 뿌릴 수 있는 땅
int garden[55][55];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int totalAbleArea = 0;
pair<int, int> point[10];

void nCr(int n, int depth) {
    if (n - 1 > totalAbleArea) {
        return;
    }

    if (depth == green + red) {
    }
}

int main(void) {
    cin >> row >> col >> green >> red;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> garden[i][j];

            if (garden[i][j] == 2) {
                point[totalAbleArea] = {i, j};
                totalAbleArea++;
            }
        }
    }
}