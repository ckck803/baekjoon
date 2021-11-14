#include <bits/stdc++.h>
using namespace std;

int n;
int Dday = 1;

int main(void) {
    cin >> n;
    vector<int> time(n);

    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }

    sort(time.begin(), time.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        int take_time = time[i];
        if (Dday < take_time + (i + 1) + 1) {
            Dday = take_time + (i + 1) + 1;
        }
    }

    cout << Dday << '\n';
    return 0;
}