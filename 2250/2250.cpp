#include <bits/stdc++.h>
using namespace std;

struct Node {
    int parent = 0;
    int left;
    int right;
};

int n, numbers;
int max_depth;
Node tree[10001];
pair<int, int> depths[10001];

void init() {
    for (int i = 1; i < 10001; i++) {
        depths[i].first = 987654321;
        depths[i].second = 0;
    }
}

void updateValue(int depth) {
    numbers++;
    if (depths[depth].first > numbers) {
        depths[depth].first = numbers;
    }

    if (depths[depth].second < numbers) {
        depths[depth].second = numbers;
    }

    if (max_depth < depth) {
        max_depth = depth;
    }
}

void dfs(int num, int depth) {
    if (tree[num].left != -1) {
        int next = tree[num].left;
        dfs(next, depth + 1);
    }

    updateValue(depth);

    if (tree[num].right != -1) {
        int next = tree[num].right;
        dfs(next, depth + 1);
    }
}

int main(void) {
    cin >> n;
    init();
    ;
    for (int i = 1; i <= n; i++) {
        int value, left, right;
        cin >> value >> left >> right;

        tree[value].left = left;
        tree[value].right = right;

        if (left != -1) {
            tree[left].parent = value;
        }

        if (right != -1) {
            tree[right].parent = value;
        }
    }

    int start_index;
    for (int i = 1; i <= n; i++) {
        if (tree[i].parent == 0) {
            start_index = i;
        }
    }

    dfs(start_index, 1);

    int max_width = 0;
    int index_of_max_width;
    for (int i = 1; i <= max_depth; i++) {
        if (max_width < depths[i].second - depths[i].first + 1) {
            max_width = depths[i].second - depths[i].first + 1;
            index_of_max_width = i;
        }
    }

    cout << index_of_max_width << " " << max_width << '\n';
    return 0;
}