#include <bits/stdc++.h>
using namespace std;

map<int, int> h1, h2;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        auto iter = h1.lower_bound(value);
        int m = 0;
        if (iter != h1.end())
            m = max(m, iter->second);
        if (iter != h1.begin()) {
            iter--;
            m = max(m, iter->second);
        }

        h1[value] = 1 + m;
        ans += 1 + (long long)m;
    }

    cout << ans << '\n';
    return 0;
}