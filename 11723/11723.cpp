#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[21];

void operateCommand(string command) {
    int x;

    if (command == "add") {
        cin >> x;
        arr[x] = 1;
    } else if (command == "remove") {
        cin >> x;
        arr[x] = 0;
    } else if (command == "check") {
        cin >> x;
        if (arr[x]) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    } else if (command == "toggle") {
        cin >> x;
        if (arr[x]) {
            arr[x] = 0;
        } else {
            arr[x] = 1;
        }
    } else if (command == "all") {
        for (int i = 1; i <= 20; i++) {
            arr[i] = 1;
        }
    } else if (command == "empty") {
        for (int i = 1; i <= 20; i++) {
            arr[i] = 0;
        }
    }
}

int main(void) {
    int n;
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;

    while (n--) {
        string command;
        cin >> command;
        operateCommand(command);
    }

    return 0;
}