#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

const int P = 131;
const int maxn = 200000 + 10;

ULL h1[maxn], h2[maxn];
ULL pb[maxn];
char s[maxn];
int match[maxn];
int cnt[maxn];

inline bool check(int i, int len) {
    return h1[i + len - 1] - h1[i - 1] * pb[len] == h2[len];
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        h1[i] = h1[i - 1] * P + s[i] - 'a';
    }
    scanf("%s", s + 1);
    for (int i = 1; i <= m; i++) {
        h2[i] = h2[i - 1] * P + s[i] - 'a';
    }

    int N = max(n, m);
    pb[0] = 1;
    for (int i = 1; i <= N; i++) {
        pb[i] = pb[i - 1] * P;
    }

    for (int i = 1; i <= n; i++) {
        int L = 0, R = min(n - i + 1, m);
        int M;
        while (L < R) {
            M = (L + R + 1) >> 1;
            if (check(i, M))
                L = M;
            else
                R = M - 1;
        }
        match[i] = L;
    }

    for (int i = 1; i <= n; i++)
        cnt[match[i]]++;

    int t;
    while (q--) {
        scanf("%d", &t);
        printf("%d\n", cnt[t]);
    }

    return 0;
}