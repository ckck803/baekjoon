#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char field[51][51];
bool check[51][51][1 << 5];
int row, col;
int startX, startY;
int device = 0;
int minValue = INT_MAX;

struct status {
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
                field[i][j] = device + '0';
                device++;
            }
        }
    }

    queue<status> q;
    q.push({startY, startX, 0});
    check[startY][startX][0] = true;

    int time = 0;
    while (!q.empty()) {
        int q_size = q.size();

        while (q_size--) {
            int cntY = q.front().y;
            int cntX = q.front().x;
            int cntDevice = q.front().device;
            q.pop();

            if (field[cntY][cntX] == 'E' && cntDevice == (1 << device) - 1) {
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

                if ('0' <= field[ny][nx] && field[ny][nx] <= '5') {
                    int number = field[ny][nx] - '0';
                    int nextDevice = cntDevice | (1 << number);

                    if (check[ny][nx][nextDevice])
                        continue;

                    check[ny][nx][nextDevice] = true;
                    q.push({ny, nx, nextDevice});
                } else {
                    if (check[ny][nx][cntDevice])
                        continue;

                    check[ny][nx][cntDevice] = true;
                    q.push({ny, nx, cntDevice});
                }
            }
        }
        time++;
    }
    return 0;
}