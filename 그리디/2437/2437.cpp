#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;

int main(void) {
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (sum + 2 <= v[i]) {
            break;
        }
        sum += v[i];
    }

    cout << sum + 1 << '\n';
    return 0;
}