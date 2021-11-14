#include <bits/stdc++.h>
using namespace std;

int N, M;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    vector<int> a(N);
    vector<int> b(M);
    vector<int> c;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < M; j++) {
        cin >> b[j];
    }

    int indexA = 0;
    int indexB = 0;
    while (indexA < N && indexB < M) {
        if (a[indexA] < b[indexB]) {
            c.push_back(a[indexA]);
            indexA++;
        } else {
            c.push_back(b[indexB]);
            indexB++;
        }
    }

    while (indexA < N) {
        c.push_back(a[indexA]);
        indexA++;
    }
    while (indexB < M) {
        c.push_back(b[indexB]);
        indexB++;
    }

    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    return 0;
}