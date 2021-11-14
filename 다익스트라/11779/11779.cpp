#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define INF 1000000000

int n, m;
int start, goal;
int trace[1001];
vector<int> dist;
vector<vector<pair<int, int>>> graph;

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        int cntDist = -pq.top().first;
        int cntVertex = pq.top().second;
        pq.pop();

        if (cntDist > dist[cntVertex]) {
            continue;
        }

        for (int i = 0; i < graph[cntVertex].size(); i++) {
            int next = graph[cntVertex][i].first;
            int nextDist = graph[cntVertex][i].second + cntDist;

            if (dist[next] > nextDist) {
                dist[next] = nextDist;
                pq.push({ -nextDist, next });

                trace[next] = cntVertex;
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;

    graph = vector<vector<pair<int, int>>>(n + 1);
    dist = vector<int>(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({ b, w });
    }
    cin >> start >> goal;

    dijkstra(start);

    cout << dist[goal] << '\n';

    stack<int> st;
    int cnt = goal;
    while (cnt) {
        st.push(cnt);
        cnt = trace[cnt];
    }

    int st_size = st.size();
    cout << st_size << endl;
    for (; !st.empty(); st.pop()) {
        cout << st.top() << " ";
    }

    return 0;
}