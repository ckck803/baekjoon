#include <bits/stdc++.h>
using namespace std;

int row, col;
int board[505][505];
int boll[505][505];
pair<int, int> root[505][505];
int check[505][505];
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

pair<int, int> RoleBall(int y, int x) {
    int minValue = 987654321;
    int nextY;
    int nextX;
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < row && 0 <= nx && nx < col) {
            if (minValue > board[ny][nx]) {
                minValue = board[ny][nx];
                nextY = ny;
                nextX = nx;
            }
        }
    }

    if (board[y][x] < minValue) {
        return {y, x};
    } else {
        pair<int, int> finish;
        if (root[nextY][nextX] == make_pair(-1, -1)) {
            boll[nextY][nextX] += boll[y][x];
            boll[y][x] = 0;
            finish = RoleBall(nextY, nextX);
        } else {
            finish = root[nextY][nextX];
            boll[finish.first][finish.second] += boll[y][x];
            boll[y][x] = 0;
        }
        root[y][x] = finish;
        return finish;
    }
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            boll[i][j] = 1;
            root[i][j].first = -1;
            root[i][j].second = -1;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (boll[i][j] != 0) {
                RoleBall(i, j);
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << boll[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}