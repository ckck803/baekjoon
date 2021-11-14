#include <iostream>
#include <vector>
using namespace std;

int n, m;

int main(void) {
    cin >> n >> m;
    if (n == 1 || m == 1) {
        cout << 1 << '\n';
        return 0;
    }

    if (n >= 3) {
        if (m >= 7) {
            cout << m - 2 << '\n';
        } else if (m >= 4) {
            cout << 4 << '\n';
        } else {
            cout << m << '\n';
        }
    } else {
        m--;

        if (m >= 6) {
            cout << 4 << '\n';
        } else if (m >= 2) {
            cout << m / 2 + 1 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}