#include <iostream>
#include <vector>
using namespace std;

int N;
// int board[11][11];
int board[11 * 11];
int maxValue = 0;
int num = 0;
vector<int> point;

bool isPossible(int k) {
    int cntValue = k - N;
    int i = 1;
    bool isTrue = true;
    while (cntValue > 0) {
        int LeftIndex = cntValue - 1;
        int RightIndex = cntValue + 1;

        if (LeftIndex >= 0 && board[LeftIndex] == 2) {
            isTrue = false;
            break;
        }
        if (RightIndex <= N && board[RightIndex] == 2) {
            isTrue = false;
            break;
        }
    }

    return isTrue;
}

void putBishop(int index) {
    if (maxValue < num) {
        cout << maxValue << '\n';
        maxValue = num;
    }

    for (int i = index; i < N * N; i++) {
        if (board[i] == 1) {
            if (isPossible(i)) {
                num++;
                board[i] = 2;
                putBishop(i + 1);
                board[i] = 1;
                num--;
            }
        }
    }
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[N * i + j];

            if (board[N * i + j] == 1) {
                point.push_back(N * i + j);
            }
        }
    }

    putBishop(0);
    cout << maxValue << '\n';
}