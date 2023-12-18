#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
const int maxsize = 15;
struct Trie {
    int tot, child[maxn][maxsize];
    int val[maxn];
    void init() {
        tot = 0;
        memset(child[0], -1, sizeof(child[0]));
        memset(val, 0, sizeof(val));
    }
    void Insert(char *s, int v) {
        int root = 0;
        for (int i = 0; s[i]; i++) {
            int index;
            if (s[i] == 'x' || s[i] == 'X') index = 10;
            else index = s[i] - '0';
            int u = child[root][index];
            if (u == -1) {
                u = ++tot;
                memset(child[u], -1, sizeof(child[u]));
                child[root][index] = u;
            }
            root = u;
        }
        val[root] += v;
    }
    int Query(char *s) {
        int root = 0;
        for (int i = 0; s[i]; i++) {
            int index;
            if (s[i] == 'x' || s[i] == 'X') index = 10;
            else index = s[i] - '0';
            int u = child[root][index];
            if (u == -1) return -1;
            root = u;
        }
        return val[root];
    }
}trie;
int main() {
    trie.init();
    char str[20];
    int n, k, x; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s%d", str, &x);
        if (x < k) x = k;
        trie.Insert(str, x);
    }
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%s", str);
        x = trie.Query(str);
        if (x != -1) printf("%d\n", x);
        else printf("No Info\n");
    }
}