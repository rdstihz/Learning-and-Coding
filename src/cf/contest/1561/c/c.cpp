/*
    Created by $%U%$ at $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 10;
const int INF = 2e9;
int minv[maxn], addv[maxn];
int q[maxn];
int n;

bool cmp(int a, int b) {
    return minv[a] < minv[b];
}
bool check(int x) {
    for (int e = 1, i; e <= n; e++) {
        i = q[e];
        if (minv[i] >= x) return false;
        x += addv[i];
    }
    return true;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", addv + i);
        int v;
        minv[i] = 0;
        for (int j = 0; j < addv[i]; j++) {
            scanf("%d", &v);
            minv[i] = max(minv[i], v - j);
        }
    }
    for (int i = 1; i <= n; i++)
        q[i] = i;
    sort(q + 1, q + 1 + n, cmp);

    int L = 0, R = 1e9 + 10;
    int M = L + R >> 1;
    while (L < R) {
        M = L + R >> 1;
        if (check(M))
            R = M;
        else
            L = M + 1;
    }
    printf("%d\n", L);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}