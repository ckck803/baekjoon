#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1000000000

int V, E;
int start;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    dist[start] = 0;

    while (!pq.empty()) {
        int cntDist = -pq.top().first;
        int cntVertex = pq.top().second;
        pq.pop();

        if (dist[cntVertex] < cntDist) {
            continue;
        }

        for (int i = 0; i < graph[cntVertex].size(); i++) {
            int next = graph[cntVertex][i].first;
            int nextValue = graph[cntVertex][i].second;

            if (dist[next] > cntDist + nextValue) {
                dist[next] = cntDist + nextValue;
                pq.push({-(cntDist + nextValue), next});
            }
        }
    }
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> V >> E;
    cin >> start;

    graph = vector<vector<pair<int, int>>>(V + 1);
    dist = vector<int>(V + 1, INF);

    for (int i = 0; i < E; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({b, w});
    }

    dijkstra(start);

    for (int i = 1; i < dist.size(); i++) {
        if (dist[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}