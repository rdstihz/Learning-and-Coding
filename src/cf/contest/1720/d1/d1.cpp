/*
    Created by rdstihz at 2022-08-18 22:54:26
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 300000 + 100;

int trie[maxn * 30][2], root, tot;
int f[maxn * 30][2];
int dp[maxn];
int a[maxn];

int newnode() {
    tot++;
    trie[tot][0] = trie[tot][1] = 0;
    f[tot][0] = f[tot][1] = 0;
    return tot;
}

void query(int ai, int i) {
    int x = ai ^ i;
    int cur = root;
    dp[i] = 0;
    for(int j = 29; j >= 0; j--) {
        int v = x >> j & 1;
        dp[i] = max(dp[i], f[trie[cur][!v]][i >> j & 1]);
        cur = trie[cur][v];
        if(!cur) break;
    }
    dp[i]++;
}

void insert(int ai,int i) {
    int x = ai ^ i;
    int cur = root;
    for(int j = 29; j >= 0; j--) {
        int v = x >> j & 1;
        if(!trie[cur][v])
            trie[cur][v] = newnode();
        cur = trie[cur][v];

        f[cur][ai >> j & 1] = max(f[cur][ai >> j & 1], dp[i]);
    }
}

void solve() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    tot = 0;
    root = newnode();
    for(int i = 0; i < n; i++ ) {
        query(a[i], i);
        insert(a[i], i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}