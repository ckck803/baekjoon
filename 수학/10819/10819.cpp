#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(void) {
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int maxValue = -987654321;
    do {
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += abs(v[i] - v[i + 1]);
        }

        maxValue = max(maxValue, sum);
    } while (next_permutation(v.begin(), v.end()));

    cout << maxValue << '\n';
    return 0;
}