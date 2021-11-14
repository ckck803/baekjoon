#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

int main(void) {
    int front, back;

    scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     v.push_back(i + 1);
    // }

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    while (true) {
        front = n;
        back = n;

        //arr[i-1]<a[i] 인 i를 찾기
        for (int i = 0; i < n - 1; i++) {
            if (v[i] < v[i + 1]) {
                front = i;
            }
        }

        if (front == n) {
            break;
        }

        //arr[i-1]<a[j] 인 j를 찾기
        for (int i = front; i < n; i++) {
            if (v[front] < v[i]) {
                back = i;
            }
        }

        //arr[i-1]과 a[j]를 swap하기
        swap(v[front], v[back]);

        //a[j+1]부터 정렬하기
        sort(v.begin() + front + 1, v.end());

        for (int i = 0; i < n; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    }

    return 0;
}