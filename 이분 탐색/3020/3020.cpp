#include <algorithm>
#include <iostream>
using namespace std;

#define INF 987654321

int N, H;
int newN;
int obstacleOdd[100001];
int obstacleEven[100001];
int obstacle[200002];
int MinValue = INF;

int main(void) {
    cin >> N >> H;
    newN = N / 2;

    for (int i = 0; i < newN; i++) {
        cin >> obstacleOdd[i] >> obstacleEven[i];
    }

    sort(obstacleOdd, obstacleOdd + newN);
    sort(obstacleEven, obstacleEven + newN);

    for (int i = 1; i <= H; i++) {
        int down = newN - (lower_bound(obstacleOdd, obstacleOdd + newN, i) - obstacleOdd);
        int up = newN - (upper_bound(obstacleEven, obstacleEven + newN, H - i) - obstacleEven);

        int totalNum = down + up;

        if (MinValue >= totalNum) {
            MinValue = totalNum;
            obstacle[MinValue]++;
        }
    }

    cout << MinValue << " " << obstacle[MinValue] << "\n";
    return 0;
}