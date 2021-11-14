#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int a, b;
    char w;

    while (true) {
        string s1, s2;
        int a, b;
        char w;
        cin >> s1 >> w >> s2;

        a = stoi(s1);
        b = stoi(s2);

        if (a == 0 && w == 'W' && b == 0) {
            break;
        }

        if (w == 'W') {
            if (a - b < -200) {
                cout << "Not allowed" << '\n';
            } else {
                cout << a - b << '\n';
            }
        } else {
            cout << a + b << endl;
        }
    }
    return 0;
}