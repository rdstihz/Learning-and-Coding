#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 10;
const int maxm = 20000 + 100;

long long f[maxm], g[maxm];

int q[maxm], l, r;

int v[maxn], w[maxn], s[maxn];

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        memcpy(g, f, sizeof(f));

        for (int j = 0; j < v[i]; j++) {
            l = r = 0;
            q[++r] = 0;

            for (int a = 1; j + a * v[i] <= m; a++) {

                while (l < r && a - q[l + 1] > s[i])
                    l++;

                while (l < r && g[j + a * v[i]] - a * w[i] >= g[j + q[r] * v[i]] - q[r] * w[i])
                    r--;
                q[++r] = a;

                int b = q[l + 1];
                f[j + a * v[i]] = g[j + b * v[i]] + (a - b) * w[i];
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}