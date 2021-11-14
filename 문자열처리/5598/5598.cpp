#include <iostream>
#include <string>
using namespace std;

string s;

int main(void) {
    cin >> s;

    string result;
    for (int i = 0; i < s.length(); i++) {
        result += ((s[i] - 'A') + 26 - 3) % 26 + 'A';
    }

    cout << result << '\n';
    return 0;
}