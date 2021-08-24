/*
    Created by $%U%$ at $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 4000000 + 100;
typedef long long LL;
LL f[maxn];

vector<int> p, c;
vector<int> primes;
bool flag[maxn];
void init(int N) {
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            primes.push_back(i);
        }
        for (int j : primes) {
            if (i * j > N) break;
            flag[i * j] = true;
            if (i % j == 0)
                break;
        }
    }
}

void div(int x) {
    p.clear(), c.clear();
    for (int j = 0; j < primes.size() && primes[j] * primes[j] <= x; j++) {
        if (x % primes[j] == 0) {
            p.push_back(primes[j]);
            c.push_back(0);
            while (x % primes[j] == 0)
                x /= primes[j], c.back()++;
        }
    }
    if (x > 1) p.push_back(x), c.push_back(1);
}

int n, m;
LL val;
void dfs(int d, int cur, int x) {
    if (d == p.size()) {
        if (cur == 1) return;
        if (cur != x) val = (val + m - f[(x - 1) / cur]) % m;
        val = (val + f[x / cur]) % m;
        return;
    }

    for (int i = 0; i <= c[d]; i++) {
        dfs(d + 1, cur, x);
        cur *= p[d];
    }
}


int main() {
    scanf("%d%d", &n, &m);
    init(n);

    LL sum = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = sum;
        div(i);
        //val = 0;
        dfs(0, 1, i);
        f[i] = (f[i] + val) % m;
        sum = (sum + f[i]) % m;
    }
    printf("%lld\n", f[n]);
    return 0;
}