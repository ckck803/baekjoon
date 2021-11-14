#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> v(10);

    for (int i = 0; i < 10; i++) {
        v[i] = i + 5;
    }
    for (int i = 0; i < 10; i++) {
        cout << v[i] << ' ';
    }
    cout << endl;

    cout << lower_bound(v.begin(), v.end(), 20) - v.begin() << endl;
}