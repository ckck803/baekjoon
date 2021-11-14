#include <bits/stdc++.h>
using namespace std;

int test_case, height, width;
vector<vector<char>> prison;
vector<pair<int, int>> prisoner;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<pair<int, int>> init() {
    vector<pair<int, int>> prisoners;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> prison[i][j];

            if (prison[i][j] == '$') {
                prisoners.push_back({i, j});
                prison[i][j] = '.';
            }
        }
    }
    return prisoners;
}

int bfs(int y, int x, vector<vector<char>> Map) {
    vector<vector<bool>> check = vector<vector<bool>>(height, vector<bool>(width, false));
    queue<pair<int, int>> q;
    q.push({y, x});
    check[y][x] = true;

    while (!q.empty()) {
        int cntY = q.front().first;
        int cntX = q.front().second;
        q.pop();
    }
}

int singleEscape(int y, int x) {
    vector<vector<char>> copied_prison(prison);
    int count1 = bfs(prisoner[0].first, prisoner[0].second, copied_prison);
    int count2 = bfs(prisoner[1].first, prisoner[1].second, copied_prison);
}

int main(void) {
    cin >> test_case;

    while (test_case--) {
        cin >> height >> width;
        prison = vector<vector<char>>(height, vector<char>(width));
        prisoner = init();
    }
}