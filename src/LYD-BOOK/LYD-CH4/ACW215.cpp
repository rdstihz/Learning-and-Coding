#include <cmath>
#include <iostream>

using namespace std;

const int maxn = 50000 + 100;

int mu[maxn];
int prime[maxn], tot;
bool flag[maxn];

void init() {

    int N = 50000;
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            prime[++tot] = i;
            mu[i] = -1;
        }

        for (int j = 1; j <= tot && i * prime[j] <= N; j++) {
            flag[i * prime[j]] = true;
            mu[i * prime[j]] = -mu[i];

            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
    for (int i = 2; i <= N; i++)
        mu[i] += mu[i - 1];
}

int main() {
    int T;
    cin >> T;
    init();
    while (T--) {
        int a, b, d;
        cin >> a >> b >> d;
        a /= d;
        b /= d;

        long long ans = 0;
        int gd;
        for (int d = 1; d <= a; d = gd + 1) {
            if (a / d == 0 || b / d == 0)
                break;
            gd = min(a / (a / d), b / (b / d));
            if (gd > a) gd = a;

            ans += (long long)(a / d) * (b / d) * (mu[gd] - mu[d - 1]);
        }
        cout << ans << endl;
    }

    return 0;
}