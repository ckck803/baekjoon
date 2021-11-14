#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321

int N, M;
vector<pair<int, int>> price;
int totalPrice = 0;

int main(void) {
    cin >> N >> M;
    price = vector<pair<int, int>>(M);

    for (int i = 0; i < M; i++) {
        cin >> price[i].first >> price[i].second;
    }

    while (N > 0) {
        int minPrice = INF;

        if (N >= 6) {
            for (int i = 0; i < M; i++) {
                int packagePrice = price[i].first;
                int eachPrice = price[i].second;

                int moreCheap = min(packagePrice, eachPrice * 6);

                minPrice = min(minPrice, moreCheap);
            }
        } else {
            for (int i = 0; i < M; i++) {
                int packagePrice = price[i].first;
                int eachPrice = price[i].second;

                int moreCheap = min(packagePrice, eachPrice * N);

                minPrice = min(minPrice, moreCheap);
            }
        }
        totalPrice += minPrice;
        N -= 6;
    }
    cout << totalPrice << '\n';
    return 0;
}