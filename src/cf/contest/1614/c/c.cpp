/*
    Created by rdstihz at 2021-11-26 19:42:30
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL P = 1e9 + 7;
const int maxn = 200000 + 100;

struct Seg {
    int l, r, v;
    bool operator<(const Seg& phs) const {
        if(l != phs.l) return l < phs.l;
        else return r < phs.r;
    }
} a[maxn];
LL B[maxn];
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].v);
    }
    sort(a + 1, a + 1 + m);
   
    LL res = 0;
    for(int k = 0; k <= 30; k++) {
        int cnt = 0;
        int last = 0, pos = 0;
        for(int i = 1; i <= m; i++) {
            int t = a[i].v >> k & 1;
            if(!t) last = a[i].r;
            else {
                if(pos < a[i].l) {
                    pos = max(last + 1, a[i].l);
                    cnt++;
                }
            }
        }
        res = (res + B[cnt - 1] * B[k] % P * B[n - cnt] % P) % P;
    }
    printf("%lld\n", res);
}

int main() {

    B[0] = 1;
    for(int i = 1; i <= 200010; i++)
        B[i] = 2 * B[i - 1] % P;

    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}