#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000000000000000

int N;
map<long long, int> m;
long long arr[101];
bool check[101];
long long answer[101];
int flag = false;

void d3m2(long long value, int num) {
    if (flag) {
        return;
    }

    if (num == N) {
        for (int i = 0; i < N; i++) {
            cout << answer[i] << " ";
        }
        cout << '\n';
        flag = true;
        return;
    }

    if (value % 3 == 0 && m.find(value / 3) != m.end() && m[value / 3] > 0) {
        m[value / 3]--;
        answer[num] = value / 3;
        d3m2(value / 3, num + 1);
        m[value / 3]++;
    }

    if (value * 2 <= MAX && m.find(value * 2) != m.end() && m[value * 2] > 0) {
        m[value * 2]--;
        answer[num] = value * 2;
        d3m2(value * 2, num + 1);
        m[value * 2]++;
    }
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (m.find(arr[i]) == m.end()) {
            m[arr[i]] = 1;
        } else {
            m[arr[i]]++;
        }
    }

    for (int i = 0; i < N; i++) {
        long long cntValue = arr[i];
        m[cntValue]--;
        answer[0] = cntValue;
        d3m2(cntValue, 1);
        m[cntValue]++;
    }

    return 0;
}