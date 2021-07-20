#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 * 31 + 100;
int trie[maxn][2], tot, root;
int n, k;
int a[maxn];

int ans, l;
int last[maxn];
void insert(int val, int id) {
    int cur = root;
    for (int i = 30; i >= 0; i--) {
        int v = val >> i & 1;
        if (trie[cur][v] == 0) {
            trie[cur][v] = ++tot;
        }
        cur = trie[cur][v];
        last[cur] = id;
    }
}

void query(int val, int id) {
    int t = 0;
    int cur = root;
    for (int i = 30; i >= 0; i--) {
        int v = val >> i & 1;
        if (trie[cur][!v]) {
            cur = trie[cur][!v];
            t |= 1 << i;
        } else
            cur = trie[cur][v];

        if (t >= k) {
            if (ans > id - last[cur] || ans == id - last[cur] && last[cur] < l) {
                ans = id - last[cur];
                l = last[cur];
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(trie, 0, sizeof(trie));

        tot = 0;
        root = ++tot;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            a[i] ^= a[i - 1];
        }

        insert(0, 0);
        ans = n + 1, l = 0;

        for (int i = 1; i <= n; i++) {
            query(a[i], i);
            insert(a[i], i);
        }
        if (ans > n)
            printf("-1\n");
        else
            printf("%d %d\n", l + 1, l + ans);
    }

    return 0;
}