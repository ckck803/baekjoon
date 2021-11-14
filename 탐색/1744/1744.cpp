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

    int minus_zero_to_plus = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= 0) {
            minus_zero_to_plus = i;
        } else {
            break;
        }
    }

    int sum = 0;

    for (int i = v.size() - 1; i >= minus_zero_to_plus + 1; i--) {
        if (i - 1 >= 0 && v[i] > 1 && v[i - 1] > 1) {
            sum += v[i] * v[i - 1];
            i--;
        } else {
            sum += v[i];
        }
    }
    for (int i = 0; i <= minus_zero_to_plus; i++) {
        if (i + 1 <= minus_zero_to_plus) {
            sum += v[i] * v[i + 1];
            i++;
        } else {
            sum += v[i];
        }
    }

    cout << sum << '\n';

    return 0;
}