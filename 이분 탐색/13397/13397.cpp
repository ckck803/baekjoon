#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    int arr[5000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = 9999;

    while (left <= right) {
        int mid = (left + right) / 2;
        int cntM = 1;
        int maxVal = arr[0];
        int minVal = arr[0];

        for (int i = 1; i < n; i++) {
            if (maxVal < arr[i])
                maxVal = arr[i];
            if (minVal > arr[i])
                minVal = arr[i];

            if (maxVal - minVal > mid) {
                minVal = arr[i];
                maxVal = arr[i];
                cntM++;
            }
        }

        if (cntM > m) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << left << '\n';
    return 0;
}