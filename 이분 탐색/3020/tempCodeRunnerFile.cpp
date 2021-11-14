#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

#define INF 987654321;

int N, H;
int obstacleOdd[100010];
int obstacleEven[100010];
int minValue = INF;
int oddNum;
int evenNum;
int midHeight;
map<int, int> m;

int breakStonesOdd(int k) {
    int num = 0;
    for (int i = 1; i <= N / 2; i++) {
        if (obstacleOdd[i] >= k) {
            num++;
        }
    }

    return num;
}

int breakStoneEven(int k) {
    int num = 0;
    for (int i = 1; i <= N / 2; i++) {
        if (obstacleEven[i] + k > H) {
            num++;
        }
    }

    return num;
}

bool breakStone1(int k) {
    int odd = breakStonesOdd(k);
    int even = breakStoneEven(k);

    if (minValue > odd + even) {
        minValue = odd + even;
        m.insert({minValue, 1});
        return true;
    } else if (minValue == odd + even) {
        m[minValue]++;
    }
    return false;
}

bool breakStone2(int k) {
    int odd = breakStonesOdd(k);
    int even = breakStoneEven(k);

    if (minValue > odd + even) {
        minValue = odd + even;

        if (m.find(minValue) == m.end()) {
            m.insert({minValue, 1});
        } else {
            m[minValue]++;
        }
        return true;
    } else if (minValue == odd + even) {
        if (k != midHeight) {
            m[minValue]++;
        }
    }
    return false;
}

int main(void) {
    cin >> N >> H;
    for (int i = 1; i <= N / 2; i++) {
        cin >> obstacleOdd[i];
        cin >> obstacleEven[i];
    }

    sort(obstacleOdd, obstacleOdd + N / 2);
    sort(obstacleEven, obstacleEven + N / 2);
    midHeight = (1 + H) / 2;

    int start = 1;
    int finish = H;
    while (start <= finish) {
        int mid = (start + finish) / 2;

        if (breakStone1(mid)) {
            start = mid + 1;
        } else {
            finish = mid - 1;
        }
    }

    start = 1;
    finish = H;
    while (start <= finish) {
        int mid = (start + finish) / 2;

        if (breakStone2(mid)) {
            start = mid + 1;
        } else {
            finish = mid - 1;
        }
    }

    cout << minValue << " " << m[minValue] << '\n';
}