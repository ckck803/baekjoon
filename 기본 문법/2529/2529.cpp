#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
int n;
bool check[10];
int arr[10];
int arr2[10];

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        s += c;
    }

    int cntNum = 9;
    for (int i = 0; i < s.size(); i++) {
        int start = i;
        while (i < s.size() && s[i] == '<') {
            i++;
        }

        for (int j = i; j >= start; j--) {
            arr[j] = cntNum--;
        }

        if (i == s.size() - 1 && s[i] == '>') {
            arr[i + 1] = cntNum--;
        }
    }

    int number = s.size();
    for (int i = s.size() - 1; i >= 0; i--) {
        int start = i;
        while (i >= 0 && s[i] == '>') {
            i--;
        }

        for (int j = i; j <= start; j++) {
            arr2[j + 1] = number--;
        }

        if (i == 0 && s[i] == '<') {
            arr2[i] = number--;
        }
    }

    for (int i = 0; i <= n; i++) {
        cout << arr[i];
    }
    cout << endl;
    for (int i = 0; i <= n; i++) {
        cout << arr2[i];
    }
    cout << endl;
    return 0;
}