#include <bits/stdc++.h>
using namespace std;

int X;

int main(void) {
    cin >> X;

    int num = 1;
    while (X - num > 0) {
        X -= num;
        num++;
    }

    if (X - num == 0) {
        if (num % 2 == 1) {
            cout << 1 << '/' << num << '\n';
        } else {
            cout << num << '/' << 1 << '\n';
        }
    } else {
        if (num % 2 == 1) {
            cout << num - X + 1 << '/' << X << '\n';
        } else {
            cout << X << '/' << num - X + 1 << '\n';
        }
    }

    return 0;
}