#include <iostream>
using namespace std;

int numOfColumn;
int columns[1010];
int sum = 0;

int main(void) {
    cin >> numOfColumn;

    int lastIndex = 0;
    int maxHeight = 0;
    int startIndexOfMaxHeight = 0;
    int lastIndexOfMaxHeight = 0;
    for (int i = 0; i < numOfColumn; i++) {
        int index, height;
        cin >> index >> height;
        columns[index] = height;
        lastIndex = max(lastIndex, index);
    }

    for (int i = 0; i <= lastIndex; i++) {
        if (maxHeight < columns[i]) {
            startIndexOfMaxHeight = i;
            maxHeight = columns[i];
        }
    }

    maxHeight = 0;
    for (int i = lastIndex; i >= 0; i--) {
        if (maxHeight < columns[i]) {
            lastIndexOfMaxHeight = i;
            maxHeight = columns[i];
        }
    }

    sum += maxHeight * (lastIndexOfMaxHeight - startIndexOfMaxHeight + 1);

    int cnt_width = 0;
    int cnt_height = 0;
    for (int i = 0; i <= startIndexOfMaxHeight; i++) {
        if (cnt_height < columns[i]) {
            sum += cnt_width * cnt_height;
            cnt_width = 0;
            cnt_height = columns[i];
        }
        cnt_width++;
    }

    cnt_width = 0;
    cnt_height = columns[lastIndex];
    for (int i = lastIndex; i >= lastIndexOfMaxHeight; i--) {
        if (cnt_height < columns[i]) {
            sum += cnt_width * cnt_height;
            cnt_width = 0;
            cnt_height = columns[i];
        }
        cnt_width++;
    }

    cout << sum << '\n';
    return 0;
}