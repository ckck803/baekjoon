#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[110][110];
int dis[110][110];
int network[110];
pair<int, int> minValue;

void dfs(int start, int cnt)
{
    for (int i = 1; i <= N; i++) {
        if (arr[cnt][i] == 1 && start != i) {
            if (dis[start][i] == 0 | dis[start][i] > dis[start][cnt] + arr[cnt][i]) {
                dis[start][i] = dis[start][cnt] + arr[cnt][i];
                dis[i][start] = dis[start][cnt] + arr[cnt][i];
                dfs(start, i);
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dfs(i, j);
        }
    }

    for (int i = 1; i <= N; i++) {
        network[1] += dis[1][i];
    }
    minValue = { 1, network[1] };

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            network[i] += dis[i][j];
        }

        if (minValue.second > network[i]) {
            minValue.first = i;
            minValue.second = network[i];
        }
    }

    cout << minValue.first << '\n';
}