#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

int main(void) {
    vector<pair<string, int>> arr;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        bool IsName = false;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].first == name) {
                arr[i].second++;
                IsName = true;
            }
        }

        if (!IsName) {
            arr.push_back({name, 1});
        }
    }

    sort(arr.begin(), arr.end(), cmp);

    cout << arr[0].first << '\n';
    return 0;
}