#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

int main(void) {
    int n;
    set<string> s;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;

    string sArr[20002];
    int index = 0;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        if (s.find(temp) == s.end()) {
            s.insert(temp);
            sArr[index] = temp;
            index++;
        }
    }

    sort(sArr, sArr + index, cmp);

    for (int i = 0; i < index; i++) {
        cout << sArr[i] << '\n';
    }

    return 0;
}