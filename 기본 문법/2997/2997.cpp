#include <bits/stdc++.h>
using namespace std;

int arr[3];
int answer;

void findValue() {
    int d1 = arr[1] - arr[0];
    int d2 = arr[2] - arr[1];

    if (d1 == d2) {
        cout << arr[2] + d1 << '\n';
    } else if (d1 / 2 == d2) {
        cout << arr[0] + d2 << '\n';
    } else if (d2 / 2 == d1) {
        cout << arr[1] + d1 << '\n';
    }
}

int main(void) {
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + 3);
    findValue();
    return 0;
}