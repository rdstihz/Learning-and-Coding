#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int maxn = 100000 + 100;
const ull P = 131;
inline int lowbit(int x) {
    return x & -x;
}
int n;
ull C[maxn];
ull B[maxn];
char s[maxn];
void add(int p, ull v) {
    for (; p <= n; p += lowbit(p))
        C[p] += v;
}
ull sum(int p) {
    ull res = 0;
    for (; p; p -= lowbit(p))
        res += C[p];
    return res;
}

ull query(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    int m;
    scanf("%d%d", &n, &m);
    B[0] = 1;
    for (int i = 1; i <= n; i++)
        B[i] = B[i - 1] * P;

    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        add(i, s[i] * B[i]);
    }

    int op, l1, r1, l2, r2;
    int pos;
    char c[2], y;
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%s", &pos, c);
            y = *c;

            add(pos, -s[pos] * B[pos]);
            add(pos, y * B[pos]);
            s[pos] = y;
        } else {
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            if (r1 - l1 != r2 - l2) {
                printf("NO\n");
                continue;
            }

            int L = 0, R = r1 - l1;
            int M;

            if (l1 > l2) {
                swap(l1, l2);
                swap(r1, r2);
            }
            while (L < R) {
                M = L + R >> 1;
                if (query(l1, l1 + M) * B[l2 - l1] == query(l2, l2 + M))
                    L = M + 1;
                else
                    R = M;
            }
            if (L >= r1 - l1) {
                printf("YES\n");
                continue;
            }
            if (query(l1 + L + 1, r1) * B[l2 - l1] == query(l2 + L + 1, r2))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}