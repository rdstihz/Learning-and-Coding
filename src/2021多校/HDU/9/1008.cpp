#include <bits/stdc++.h>

using namespace std;
const int maxn = 200000 + 100;
typedef long long LL;
bool flag[2100000 + 10];
int primes[2100000], tot;

void init() {
    int N = 2100000;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            primes[++tot] = i;
        }
        for (int j = 1; j <= tot && i * primes[j] <= N; j++) {
            flag[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}
LL a[maxn];
int ans;
int n;

unordered_map<int, int> cnt;
void update(LL m) {
    cnt.clear();
    LL t;
    for (int i = 1; i <= n; i++) {
        t = a[i] % m;
        ans = max(ans, ++cnt[t]);
    }
}

void solve() {

    unordered_set<LL> S;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    ans = 1;
    for (int k = 1; k <= 50 && S.size() <= 30; k++) {
        int x = rand() % n + 1;
        int y = rand() % n + 1;
        LL d = abs(a[x] - a[y]);
        if (d <= 1) continue;

        for (int i = 1; 1ll * primes[i] * primes[i] <= d; i++) {
            if (d % primes[i] == 0) {
                while (d % primes[i] == 0)
                    d /= primes[i];
                S.insert(primes[i]);
            }
        }
        if (d > 1) S.insert(d);
    }


    for (LL v : S)
        update(v);
    printf("%d\n", ans);
}

int main() {

    int T;
    srand((unsigned)time(NULL));
    init();
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}