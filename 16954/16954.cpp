#include <bits/stdc++.h>
using namespace std;

char chess_board[8][8];
bool check[9][8][8];
int startY, startX;
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};

void move_chess_board() {
    int temp[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            temp[i][j] = chess_board[i][j];
            chess_board[i][j] = '.';
        }
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 8; j++) {
            chess_board[i + 1][j] = temp[i][j];
        }
    }
}

void init() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> chess_board[i][j];
        }
    }
    startY = 7;
    startX = 0;
}

// 욱제의 캐릭터는 가장 왼쪽 아랫 칸에 있고, 이 캐릭터는 가장 오른쪽 윗 칸으로 이동해야 한다.

int main(void) {
    init();

    queue<pair<int, int>> q;
    q.push({startY, startX});
    for (int i = 0; i < 9; i++)
        check[i][startY][startX] = true;

    while (!q.empty()) {
        int cntY = q.front().first;
        int cntX = q.front().second;
        q.pop();

        // cout << cntY << " " << cntX << endl;

        if (chess_board[cntY][cntX] == '#') {
            cout << 0 << '\n';
            return 0;
        }

        if (cntY == 0 && cntX == 7) {
            cout << 1 << '\n';
            return 0;
        }

        for (int i = 0; i < 9; i++) {
            int ny = cntY + dy[i];
            int nx = cntX + dx[i];

            if (0 > ny || ny >= 8 || 0 > nx || nx >= 8) {
                continue;
            }
            if (check[i][ny][nx] == true) {
                continue;
            }
            if (chess_board[ny][nx] == '.') {
                check[i][ny][nx] = true;
                q.push({ny, nx});
            }
        }
        move_chess_board();
    }
    cout << 0 << '\n';
    return 0;
}