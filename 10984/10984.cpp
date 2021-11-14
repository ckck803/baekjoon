#include <bits/stdc++.h>
using namespace std;

int t;

int main(void) {
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int total_num = 0;
        double total_score = 0;
        while (n--) {
            int num;
            double score;
            cin >> num >> score;
            total_num += num;
            total_score += num * score;
        }
        printf("%d %0.1f\n", total_num, total_score / total_num);
    }

    return 0;
}