#include <bits/stdc++.h>
using namespace std;

int N;
int paper[3000][3000];
int papers[3];

bool isAllSame(int y, int x, int n) {
    int color = paper[y][x];

    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (paper[i][j] != color) {
                return false;
            }
        }
    }
    return true;
}

void cutPaper(int y, int x, int n) {
    if (isAllSame(y, x, n)) {
        papers[paper[y][x] + 1]++;
        return;
    }

    cutPaper(y, x, n / 3);
    cutPaper(y, x + n / 3, n / 3);
    cutPaper(y, x + 2 * n / 3, n / 3);
    cutPaper(y + n / 3, x, n / 3);
    cutPaper(y + n / 3, x + n / 3, n / 3);
    cutPaper(y + n / 3, x + 2 * n / 3, n / 3);
    cutPaper(y + 2 * n / 3, x, n / 3);
    cutPaper(y + 2 * n / 3, x + n / 3, n / 3);
    cutPaper(y + 2 * n / 3, x + 2 * n / 3, n / 3);
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    cutPaper(0, 0, N);

    for (int i = 0; i < 3; i++) {
        cout << papers[i] << '\n';
    }

    return 0;
}