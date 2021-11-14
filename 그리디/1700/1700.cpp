#include <bits/stdc++.h>
using namespace std;

set<int> s;
int totalNum = 0;
int sizeOfPowerSocket, numOfTotalUse, numOfDevice;
int arr[101];

int main(void) {
    cin >> sizeOfPowerSocket >> numOfTotalUse;

    for (int i = 0; i < numOfTotalUse; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < numOfTotalUse; i++) {
        if (s.find(arr[i]) != s.end()) {
            continue;
        }

        if (s.size() == sizeOfPowerSocket) {
            totalNum++;
            int lastest = 0;
            int nameOfErase = 0;
            for (auto iter = s.begin(); iter != s.end(); iter++) {
                int name = *iter;

                int dist = 987654321;
                for (int j = i + 1; j < numOfTotalUse; j++) {
                    if (name == arr[j]) {
                        dist = j;
                        break;
                    }
                }

                if (lastest < dist) {
                    lastest = dist;
                    nameOfErase = name;
                }
            }
            s.erase(nameOfErase);
        }
        s.insert(arr[i]);
    }

    cout << totalNum << '\n';
    return 0;
}