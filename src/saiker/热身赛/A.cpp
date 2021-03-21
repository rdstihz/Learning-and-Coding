#include <bits/stdc++.h>

using namespace std;

const int maxn = 300000 + 100;

struct Diamond {
    int a, s;
    bool operator<(const Diamond& phs) const {
        if (s == phs.s)
            return a < phs.a;
        return s > phs.s;
    }
} d[maxn];
int n, m;

map<int, int> M;

int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i].a >> d[i].s;
    }
    int t;
    for (int i = 1; i <= m; i++) {
        cin >> t;
        if (M.count(t)) {
            M[t]++;
        } else {
            M[t] = 1;
        }
    }

    sort(d + 1, d + 1 + n);

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        t = d[i].a;
        auto it = M.lower_bound(t);

        if (it == M.end()) continue;

        ans = ans + d[i].s;
        it->second--;
        if (it->second == 0) {
            M.erase(it);
        }
    }
    cout << ans << endl;
    return 0;
}