#include <iostream>
#include <string>
using namespace std;

#define endl '\n';

string s;
int N;

int main(void) {
    cin >> s >> N;
    int length = s.length();

    int result = 0;
    for (int i = length - 1, j = 1; i >= 0; i--, j *= N) {
        int cntValue = s[i];

        if ('A' <= cntValue && cntValue <= 'Z') {
            cntValue = (cntValue - 'A') + 10;
        } else {
            cntValue = cntValue - '0';
        }
        // cout << result << " " << cntValue * j << endl;

        result += cntValue * j;
    }

    cout << result << endl;
}