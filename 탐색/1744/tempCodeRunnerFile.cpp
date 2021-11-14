#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        int cntValue = v[i];

        if (i - 1 >= 0 && v[i - 1] > 1 && v[i] > 1) {
            sum += v[i] * v[i - 1];
            i--;
        } else {
            sum += v[i];
        }
    }

    cout << sum << '\n';
    return 0;
}