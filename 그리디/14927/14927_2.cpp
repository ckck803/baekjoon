#include <bits/stdc++.h>
using namespace std;

#define MAX 20
#define INF 987654321

int Map[MAX][MAX];
int temp[MAX][MAX];
int minVal = 0;
int map_size;
int numClick = 0;
int indice[MAX];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

bool checkOff() {
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (Map[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void click(int y, int x) {
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < map_size && 0 <= nx && nx < map_size) {
            Map[ny][nx] ^= 1;
        }
    }
    numClick++;
}

void clickRest() {
    for (int i = 1; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            if (Map[i - 1][j] == 0) {
                continue;
            }
            click(i, j);
        }
    }
}

void copy_map(int target[][MAX], int origin[][MAX]) {
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            target[i][j] = origin[i][j];
        }
    }
}

void AllCases(int depth) {
    if (depth == map_size) {
        copy_map(temp, Map);
        numClick = 0;
        for (int i = 0; i < map_size; i++) {
            if (indice[i]) {
                click(0, i);
            }
        }
        clickRest();
        if (checkOff()) {
            minVal = min(minVal, numClick);
        }
        copy_map(Map, temp);
        return;
    }
    indice[depth] = 1;
    AllCases(depth + 1);
    indice[depth] = 0;
    AllCases(depth + 1);
}

int main(void) {
    cin >> map_size;
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            cin >> Map[i][j];
        }
    }

    minVal = INF;
    AllCases(0);

    if (minVal == INF)
        cout << -1 << '\n';
    else
        cout << minVal << '\n';
    return 0;
}