#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001];

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > dp[idx]) {
            idx++;
            dp[idx] = arr[i];
        } else {
            int* index = lower_bound(dp, dp + idx, arr[i]);
            *index = arr[i];
        }
    }

    cout << idx + 1 << '\n';
    return 0;
}