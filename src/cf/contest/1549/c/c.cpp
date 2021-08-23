/*
    Created by rdstihz at 2021-08-18 14:55:07
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 10;
set<int> S[maxn];
bool died[maxn];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = n;
    int op, u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        if (u < v) swap(u, v);
        if (!died[v]) {
            died[v] = true;
            ans--;
        }
        S[u].insert(v);
        S[v].insert(u);
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &u, &v);
            if (u < v) swap(u, v);
            if (!died[v]) {
                died[v] = true;
                ans--;
            }
            S[u].insert(v);
            S[v].insert(u);
        } else if (op == 2) {
            scanf("%d%d", &u, &v);
            S[u].erase(v);
            S[v].erase(u);
            if (u < v) swap(u, v);
            if (died[v] && (S[v].empty() || *(S[v].rbegin()) < v)) {
                died[v] = false;
                ans++;
            }
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}