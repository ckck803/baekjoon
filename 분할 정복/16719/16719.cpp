#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define INF 987654321
string s;
int cntNum = 1;
int charNum[101];

void makeZoac(int start, int finish) {
    int minValue = INF;
    int minIndex = 0;

    if (start == finish) {
        return;
    }

    for (int i = start; i < finish; i++) {
        if (minValue > s[i] - 'A') {
            minValue = s[i] - 'A';
            minIndex = i;
        }
    }

    charNum[minIndex] = cntNum++;
    makeZoac(minIndex + 1, finish);
    makeZoac(start, minIndex);
}

int main(void) {
    cin >> s;

    makeZoac(0, s.size());

    for (int i = 0; i < s.size(); i++) {
        int cntNum = i + 1;

        for (int j = 0; j < s.size(); j++) {
            if (charNum[j] <= cntNum) {
                cout << s[j];
            }
        }
        cout << endl;
    }
}