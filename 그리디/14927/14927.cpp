#include <bits/stdc++.h>
using namespace std;

#define MAX 20
#define INF 987654321
int Map[MAX][MAX];
int copied_map[MAX][MAX];
int map_size = 0;
int first_row[MAX];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
int numClick = 0;
int minValue = INF;

bool isAllOff() {
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
            if (Map[i - 1][j]) {
                click(i, j);
            }
        }
    }
}

void clickFirstRow() {
    for (int i = 0; i < map_size; i++) {
        if (first_row[i]) {
            click(0, i);
        }
    }
}

void copyMap(int copy[][MAX], int origin[][MAX]) {
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            copy[i][j] = origin[i][j];
        }
    }
}

void clickSwitch(int depth) {
    if (depth == map_size) {
        copyMap(copied_map, Map);
        numClick = 0;
        clickFirstRow();
        clickRest();
        if (isAllOff()) {
            minValue = min(minValue, numClick);
        }
        copyMap(Map, copied_map);
        return;
    }
    first_row[depth] = 1;
    clickSwitch(depth + 1);
    first_row[depth] = 0;
    clickSwitch(depth + 1);
}

int main(void) {
    cin >> map_size;
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            cin >> Map[i][j];
        }
    }
    clickSwitch(0);

    if (minValue == INF) {
        cout << -1 << '\n';
    } else {
        cout << minValue << '\n';
    }

    return 0;
}