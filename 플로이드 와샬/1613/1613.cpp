#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int s;
// vector<vector<int>> v(404);
int history[404][404];

void bfs(int start, int end, int number)
{
    vector<bool> check(404, false);
    queue<int> q;

    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int cnt = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            int next = i;
            int num = history[cnt][next];

            if (num == number && check[next] == false) {
                check[next] = true;

                history[start][next] = number;
                history[cnt][next] = number;

                q.push(next);
            }
        }
    }
}

int main(void)
{
    cin >> n >> k;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        history[a][b] = -1;
        history[b][a] = 1;
    }

    cin >> s;
    while (s--) {
        int case1, case2;
        cin >> case1 >> case2;

        if (history[case1][case2] == 0) {
            bfs(case1, case2, -1);
            bfs(case1, case2, 1);
        }
        cout << history[case1][case2] << '\n';
    }

    return 0;
}