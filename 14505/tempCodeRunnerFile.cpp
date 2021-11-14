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

    int min_limit = 1;
    int max_value = v[n - 1];
    while (max_value / 2 > 0) {
        min_limit *= 2;
        max_value /= 2;
    }

    int index = lower_bound(v.begin(), v.end(), min_limit) - v.begin();
    if (index == 0) {
        cout << 0 << '\n';
    } else {
        int value1 = v[index];
        int value2 = v[index - 1];
        cout << (value1 ^ value2) << '\n';
    }

    return 0;
}