#include <cstdio>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef unsigned long long ull;
const int maxn = 1010;
const int P = 131;
ull h[maxn][maxn];
char str[maxn];
ull pb[maxn * maxn];
int n, m, a, b;

ull get(ull* f, int l, int r) {
    return f[r] - f[l - 1] * pb[r - l + 1];
}

int main() {

    scanf("%d%d%d%d", &n, &m, &a, &b);

    pb[0] = 1;
    for (int i = 1; i <= n * m; i++)
        pb[i] = pb[i - 1] * P;

    for (int i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        for (int j = 1; j <= m; j++) {
            h[i][j] = h[i][j - 1] * P + str[j] - '0';
        }
    }
    unordered_set<ull> S;
    for (int i = b; i <= m; i++) {
        ull s = 0;
        int l = i - b + 1;
        int r = i;
        for (int j = 1; j <= n; j++) {
            s = s * pb[b] + get(h[j], l, r);
            if (j > a) s = s - get(h[j - a], l, r) * pb[a * b];
            if (j >= a) S.insert(s);
        }
    }

    int q;
    scanf("%d",&q);
    while(q--) {
        ull s = 0;
        for(int i = 1;i <= a;i++) {
            scanf("%s",str + 1);
            for(int j = 1;j <= b;j ++)
                s = s * P + str[j] - '0';
        }

        if(S.count(s)) puts("1");
        else puts("0");

    }

    return 0;
}