#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> arr[9];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main(void) {
    for (int i = 0; i < 8; i++) {
        arr[i].first = i + 1;
        cin >> arr[i].second;
    }
    sort(arr, arr + 8, cmp);

    vector<pair<int, int>> v;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i].second;
        v.push_back(arr[i]);
    }

    cout << sum << '\n';

    sort(v.begin(), v.end(), cmp2);

    for (int i = 0; i < 5; i++) {
        cout << v[i].first << ' ';
    }

    return 0;
}