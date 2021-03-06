#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int maxn = 200000 + 100;

bool flag[maxn];
int prime[maxn], cnt;

void init() {

    int N = 200000;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            prime[++cnt] = i;
        }

        for (int j = 1; j <= cnt && i * prime[j] <= N; j++) {
            flag[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }

    return;
}

LL a[maxn];

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    return 0;
}