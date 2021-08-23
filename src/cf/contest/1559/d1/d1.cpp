/*
    Created by rdstihz at 2021-08-15 23:13:02
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
int p1[maxn], p2[maxn];

int find1(int x) {
    return p1[x] == x ? p1[x] : p1[x] = find1(p1[x]);
}

int find2(int x) {
    return p2[x] == x ? p2[x] : p2[x] = find2(p2[x]);
}

int main() {
    int n, m1, m2;
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 1; i <= n; i++)
        p1[i] = p2[i] = i;
    int u, v;
    for (int i = 1; i <= m1; i++) {
        scanf("%d%d", &u, &v);
        u = find1(u), v = find1(v);
        p1[u] = v;
    }
    for (int i = 1; i <= m2; i++) {
        scanf("%d%d", &u, &v);
        u = find2(u), v = find2(v);
        p2[u] = v;
    }

    printf("%d\n", n - 1 - max(m1, m2));
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            int a = find1(i), b = find1(j);
            int c = find2(i), d = find2(j);
            if (a != b && c != d) {
                p1[a] = b;
                p2[c] = d;
                printf("%d %d\n", i, j);
            }
        }

    return 0;
}