#include <iostream>
#include <vector>
using namespace std;

int N, M;
int map[1010][1010];
int maxSum = 0;
vector<vector<int>> dp;

int main(void) {
    cin >> N >> M;
    dp = vector<vector<int>>(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    dp[0][0] = map[0][0];
    for (int i = 0; i < M; i++) {
        int next = i + 1;

        if (0 <= next && next < M) {
            dp[0][next] = dp[0][i] + map[0][next];
        }
    }

    for (int i = 1; i < N; i++) {
        vector<int> tempRight(M);
        vector<int> tempLeft(M);

        for (int j = 0; j < M; j++) {
            dp[i][j] = dp[i - 1][j] + map[i][j];
        }

        tempRight[0] = dp[i][0];
        for (int j = 0; j < M; j++) {
            int nextR;
            nextR = j + 1;

            if (0 <= nextR && nextR < M) {
                if (dp[i][nextR] < tempRight[j] + map[i][nextR])
                    tempRight[nextR] = tempRight[j] + map[i][nextR];
                else {
                    tempRight[nextR] = dp[i][nextR];
                }
            }
        }

        tempLeft[M - 1] = dp[i][M - 1];
        for (int j = M - 1; j >= 0; j--) {
            int nextL = j - 1;
            if (0 <= nextL && nextL < M) {
                if (dp[i][nextL] < tempLeft[j] + map[i][nextL])
                    tempLeft[nextL] = tempLeft[j] + map[i][nextL];
                else {
                    tempLeft[nextL] = dp[i][nextL];
                }
            }
        }

        for (int j = 0; j < M; j++) {
            if (tempRight[j] >= tempLeft[j]) {
                dp[i][j] = tempRight[j];
            } else {
                dp[i][j] = tempLeft[j];
            }
        }
    }
    cout << dp[N - 1][M - 1] << '\n';
    return 0;
}