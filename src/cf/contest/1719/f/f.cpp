/*
    Created by rdstihz at 2022-08-18 19:05:30
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 200000 + 100;
int a[maxn];

int p[20], cnt;
multiset<LL> S[20];
LL val[20][maxn];


LL query() {
    LL res = 0;
    for(int i = 1; i <= cnt; i++) {
        auto it = S[i].end();
        it--;
        res = max(res, (*it) * p[i]);
    }
    return res;
}

void update(int pos,int x) {
    int dt = x - a[pos];
    for(int i = 1; i <= cnt; i++) {
        LL& q = val[i][pos % p[i]];
        S[i].erase(S[i].find(q));
        q += dt;
        S[i].insert(q);
    }
    a[pos] += dt;
}

void solve() {
    int n, q;
    scanf("%d%d", &n, &q);
    
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int n1 = n;
    cnt = 0;
    for(int i = 2; i <= n1; i++) {
        if(n1 % i == 0) {
            while(n1 % i == 0) n1 /= i;

            p[++cnt] = n / i;
            S[cnt].clear();
            for(int j = 0; j < p[cnt]; j++)
                val[cnt][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= cnt; j++) {
            val[j][i % p[j]] += a[i];
        }
    }
    for(int i = 1; i <= cnt; i++) 
        for(int j = 0; j < p[i]; j++)
            S[i].insert(val[i][j]);

    LL ans = query();
    printf("%lld\n", ans);
    while(q--) {
        int pos, x;
        scanf("%d%d", &pos, &x);
        update(pos, x);
        printf("%lld\n", query());
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}