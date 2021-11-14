#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;

    while (n--) {
        string s1, s2;
        vector<int> distances;
        cin >> s1 >> s2;

        for (int i = 0; i < s1.size(); i++) {
            int distance = s2[i] - s1[i];
            if (distance < 0) {
                distance = 26 + distance;
            }
            distances.push_back(distance);
        }

        cout << "Distances: ";
        for (int i = 0; i < distances.size(); i++) {
            cout << distances[i] << " ";
        }
        cout << endl;
    }

    return 0;
}