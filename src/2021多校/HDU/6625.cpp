#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 10;

struct Trie {
    int trie[maxn * 32][2], cnt[maxn * 32];
    int tot, root;

    void init() {
        tot = 0;
        root = newnode();
    }

    int newnode() {
        tot++;
        trie[tot][0] = trie[tot][1] = 0;
        cnt[tot] = 0;
        return tot;
    }

    void insert(int x) {
        int cur = root;
        for (int i = 30; i >= 0; i--) {
            int v = x >> i & 1;
            if (!trie[cur][v])
                trie[cur][v] = newnode();
            cur = trie[cur][v];
            cnt[cur]++;
        }
    }

} T1, T2;
int n;
int ans[maxn];
void solve() {

    for (int k = 1; k <= n; k++) {
        int p1 = T1.root, p2 = T2.root;
        for (int i = 30; i >= 0; i--) {
            if (T1.cnt[T1.trie[p1][0]] && T2.cnt[T2.trie[p2][0]]) {
                p1 = T1.trie[p1][0], p2 = T2.trie[p2][0];
                T1.cnt[p1]--, T2.cnt[p2]--;
            } else if (T1.cnt[T1.trie[p1][1]] && T2.cnt[T2.trie[p2][1]]) {
                p1 = T1.trie[p1][1], p2 = T2.trie[p2][1];
                T1.cnt[p1]--, T2.cnt[p2]--;
            } else if (T1.cnt[T1.trie[p1][0]] && T2.cnt[T2.trie[p2][1]]) {
                p1 = T1.trie[p1][0], p2 = T2.trie[p2][1];
                T1.cnt[p1]--, T2.cnt[p2]--;
                ans[k] |= 1 << i;
            } else if (T1.cnt[T1.trie[p1][1]] && T2.cnt[T2.trie[p2][0]]) {
                p1 = T1.trie[p1][1], p2 = T2.trie[p2][0];
                T1.cnt[p1]--, T2.cnt[p2]--;
                ans[k] |= 1 << i;
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(ans, 0, sizeof(ans));
        T1.init(), T2.init();

        int v;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v);
            T1.insert(v);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v);
            T2.insert(v);
        }
        solve();
        sort(ans + 1, ans + 1 + n);
        for (int i = 1; i <= n; i++)
            printf("%d%c", ans[i], i == n ? '\n':' ');
        //printf("\n");
    }
    return 0;
}