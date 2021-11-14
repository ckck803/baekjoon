#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (m.find(s) == m.end()) {
            m[s] = 1;
        } else {
            m[s]++;
        }
    }

    pair<string, int> maxValue = {"", 0};
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (maxValue.second < iter->second) {
            maxValue = *iter;
        }
    }

    cout << maxValue.first << endl;
}