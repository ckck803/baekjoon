#include <bits/stdc++.h>
using namespace std;
int n, t, res;
int arr[100010];
char c[33];
struct Trie {
    Trie* go[2];
    Trie() {
        memset(go, 0, sizeof(go));
    }
    ~Trie() {
        for (int i = 0; i < 2; i++)
            if (go[i])
                delete go[i];
    }
    void insert(const char* key) {
        if (*key == '\0') {
            return;
        }
        int next = *key - '0';
        if (!go[next]) {
            go[next] = new Trie;
        }
        return go[next]->insert(key + 1);
    }
    void query(char* key) {
        if (*key == '\0') {
            return;
        }
        int next = *key - '0';
        next ^= 1;
        if (go[next]) {
            *key = '1';
            return go[next]->query(key + 1);
        } else {
            *key = '0';
            return go[next ^ 1]->query(key + 1);
        }
    }
};
int main() {
    scanf("%d", &n);
    Trie* root = new Trie;
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        for (int j = 31; j >= 0; j--) {
            if (x % 2)
                c[j] = '1';
            else
                c[j] = '0';
            x = x / 2;
        }
        c[32] = '\0';
        root->insert(c);
    }
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        for (int j = 31; j >= 0; j--) {
            if (x % 2)
                c[j] = '1';
            else
                c[j] = '0';
            x = x / 2;
        }
        c[32] = '\0';
        root->query(c);
        int y = 0;
        for (int i = 31; i >= 0; i--) {
            y += (c[i] - '0') * pow(2, 31 - i);
        }
        res = max(res, y);
    }
    printf("%d", res);
    return 0;
}