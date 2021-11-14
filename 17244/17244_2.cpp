#include <bits/stdc++.h>
using namespace std;

char field[51][51];
bool check[51][51][5];
int device = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int row, col;
int startY, startX;

struct State {
    int y;
    int x;
    int device;
};

int main(void) {
    cin >> col >> row;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> field[i][j];

            if (field[i][j] == 'S') {
                startY = i;
                startX = j;
                field[i][j] = '.';
            }

            if (field[i][j] == 'X') {
                device++;
            }
        }
    }

    queue<State> q;
    q.push({startY, startX, device});
    check[startY][startX][device] = true;

    int time = 0;
    while (!q.empty()) {
        int q_size = q.size();
        while (q_size--) {
            int cntY = q.front().y;
            int cntX = q.front().x;
            int cntDevice = q.front().device;

            if (field[cntY][cntX] == 'E' && cntDevice == 0) {
                cout << time << '\n';
                return 0;
            }

            for (int i = 0; i < 4; i++) {
                int ny = cntY + dy[i];
                int nx = cntX + dx[i];

                if (0 > ny || ny >= row || 0 > nx || nx >= col)
                    continue;

                if (field[ny][nx] == '#')
                    continue;

                if (field[ny][nx] == 'X') {
                    field[ny][nx]
                }
            }
        }
        time++;
    }

    return 0;
}