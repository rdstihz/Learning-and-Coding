#include <iostream>

using namespace std;

const int N = 100000;
bool flag[N + 10];
int prime[N], tot;

void init() {
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            prime[++tot] = i;
        }
        for (int j = 1; j <= tot && i * prime[j] <= N; j++) {
            flag[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
int get(int& x, int p) {
    int res = 0;
    while (x % p == 0) {
        res++;
        x /= p;
    }
    return res;
}

int a, b, c, d;
int ans;

void work(int p) {
    int ma = get(a, p);
    int mb = get(b, p);
    int mc = get(c, p);
    int md = get(d, p);

    if (ma == mb && mc < md && md >= mb) {
        //mx >= mb && mx = md
    } else if (ma == mb && mc == md && mb <= md) {
        //mx >= mb && mx <= md
        ans *= (md - mb + 1);
    } else if (ma > mb && mc < md && mb == md) {
        //mx == mb && mx = md
    } else if (ma > mb && mc == md && mb <= md) {
        //mx == mb && mx <= md
    } else {
        ans = 0;
    }
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;
    init();
    while (n--) {
        cin >> a >> b >> c >> d;
        ans = 1;
        for (int i = 1; i <= tot && prime[i] <= d; i++)
            if (d % prime[i] == 0) {
                work(prime[i]);
            }

        if (d > 1) {
            work(d);
        }
        cout << ans << endl;
    }
}