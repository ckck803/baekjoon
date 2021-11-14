#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

#define endl '\n'
#define MAX 1000000001;
map<long long, string> check;
long long s, t;

int main(void) {
    cin >> s >> t;
    queue<long long> q;
    q.push(s);
    check[s] = "";

    if (s == t) {
        cout << 0 << '\n';
    }

    bool isSame = false;
    while (!q.empty()) {
        long long cnt = q.front();
        string op = check[cnt];
        q.pop();

        if (cnt == t) {
            isSame = true;
            break;
        }

        long long next = 0;

        next = cnt * cnt;
        if (check.find(next) == check.end()) {
            check[next] = op + '*';
            q.push(next);
        }

        next = cnt + cnt;
        if (check.find(next) == check.end()) {
            check[next] = op + '+';
            q.push(next);
        }

        next = cnt - cnt;
        if (check.find(next) == check.end()) {
            check[next] = op + '-';
            q.push(next);
        }

        if (cnt != 0) {
            next = cnt / cnt;
            if (check.find(next) == check.end()) {
                check[next] = op + '/';
                q.push(next);
            }
        }
    }

    if (isSame) {
        cout << check[t] << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}