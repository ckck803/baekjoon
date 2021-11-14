#include <bits/stdc++.h>
using namespace std;

int T;

int main(void) {
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<string, int> m;

        for (int i = 0; i < n; i++) {
            string name, kind;
            cin >> name >> kind;

            if (m.find(kind) == m.end()) {
                m.insert({kind, 1});
            } else {
                m[kind]++;
            }
        }

        int total = 1;
        for (auto i = m.begin(); i != m.end(); i++) {
            total *= (i->second + 1);
        }

        cout << total - 1 << '\n';
    }
}