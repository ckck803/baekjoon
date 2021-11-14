#include <iostream>
#include <vector>
using namespace std;

int N, X;

int main(void) {
    cin >> N >> X;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < N; i++) {
        if (v[i] < X) {
            cout << v[i] << " ";
        }
    }
    return 0;
}