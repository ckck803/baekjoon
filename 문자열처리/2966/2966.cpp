#include <bits/stdc++.h>
using namespace std;

int n;
string answer;
int main(void) {
    cin >> n;
    cin >> answer;

    string Andrian = "ABC";
    string Bruno = "BABC";
    string Goran = "CCAABB";
    int maxNum = 0;

    int num1 = 0;
    for (int i = 0; i < answer.size();) {
        for (int j = 0; j < Andrian.size(); j++, i++) {
            if (Andrian[j] == answer[i]) {
                num1++;
            }

            if (i >= answer.size()) {
                break;
            }
        }
    }
    maxNum = max(maxNum, num1);

    int num2 = 0;
    for (int i = 0; i < answer.size();) {
        for (int j = 0; j < Bruno.size(); j++, i++) {
            if (Bruno[j] == answer[i]) {
                num2++;
            }

            if (i >= answer.size()) {
                break;
            }
        }
    }
    maxNum = max(maxNum, num2);

    int num3 = 0;
    for (int i = 0; i < answer.size();) {
        for (int j = 0; j < Goran.size(); j++, i++) {
            if (Goran[j] == answer[i]) {
                num3++;
            }

            if (i >= answer.size()) {
                break;
            }
        }
    }
    maxNum = max(maxNum, num3);

    cout << maxNum << '\n';
    if (maxNum == num1) {
        cout << "Adrian" << '\n';
    }

    if (maxNum == num2) {
        cout << "Bruno" << '\n';
    }

    if (maxNum == num3) {
        cout << "Goran" << '\n';
    }

    return 0;
}