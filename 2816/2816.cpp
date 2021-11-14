#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<string> channels;
int KBS1point, KBS2point;
int orderIndex;

int main(void) {
    cin >> N;
    channels = vector<string>(N);
    for (int i = 0; i < N; i++) {
        cin >> channels[i];

        if (channels[i] == "KBS1") {
            KBS1point = i;
        }
        if (channels[i] == "KBS2") {
            KBS2point = i;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     cout << channels[i] << " ";
    // }
    // cout << endl;

    int point = 0;
    char orders[505];
    while (true) {
        if (channels[0] == "KBS1" && channels[1] == "KBS2") {
            break;
        }

        if (point == 0 && channels[1] == "KBS1") {
            orders[orderIndex] = '3';
            orderIndex++;
            swap(channels[point], channels[point + 1]);
            point++;
            KBS1point--;
        }

        else if (point == 0 && channels[1] == "KBS2") {
            orders[orderIndex] = '3';
            orderIndex++;
            swap(channels[point], channels[point + 1]);
            point++;
            KBS2point--;
        }

        else if (point == 1 && channels[2] == "KBS2") {
            orders[orderIndex] = '3';
            orderIndex++;
            swap(channels[point], channels[point + 1]);
            point++;
            KBS2point--;
        }

        else if (point == 1 && channels[2] == "KBS1") {
            orders[orderIndex] = '3';
            orderIndex++;
            swap(channels[point], channels[point + 1]);
            point++;
            KBS1point--;
        }

        else if (channels[point] == "KBS1" && point != 0) {
            // orders[orderIndex] = '4';
            // orderIndex++;

            int orderNum = point;
            swap(channels[point], channels[0]);
            point = 0;

            // point--;
            // KBS1point--;
        }

        else if (channels[point] == "KBS2" && point != 0) {
            orders[orderIndex] = '4';
            orderIndex++;
            swap(channels[point], channels[point - 1]);
            point--;
            KBS2point--;
        }

        else if (point > KBS1point && point > KBS2point) {
            orders[orderIndex] = '2';
            orderIndex++;
            point--;
        }

        else if (channels[point] != "KBS1" || channels[point] != "KBS2") {
            orders[orderIndex] = '1';
            orderIndex++;
            point++;
        }
    }

    cout << orderIndex << endl;
    for (int i = 0; i < orderIndex; i++) {
        cout << orders[i];
    }
    return 0;
}