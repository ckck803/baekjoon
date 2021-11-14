#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
pair<int, int> arr[100001];
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main(void) {
    cin >> n;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << '\n';
    }

    return 0;
}
