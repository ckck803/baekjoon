#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s_arr[20002];

    int index = 0;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        bool isSame = false;
        for (int j = 0; j <= i; j++) {
            if (temp == s_arr[j]) {
                isSame = true;
                break;
            }
        }

        if (!isSame) {
            s_arr[index] = temp;
            index++;
        }
    }

    sort(s_arr, s_arr + index, cmp);

    for (int i = 0; i < index; i++) {
        cout << s_arr[i] << '\n';
    }

    return 0;
}