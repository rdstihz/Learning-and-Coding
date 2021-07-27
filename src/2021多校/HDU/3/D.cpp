#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
typedef pair<int, int> PII;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

PII ks[maxn];
int cnt[maxn];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int a, b, c, d;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            int x = c - a, y = d - b;
            if (x < 0) {
                x = -x;
                y = -y;
            }
            int g = gcd(x, y);
            ks[i].first = y / g;
            ks[i].second = x / g;
        }

        sort(ks + 1, ks + 1 + n);

        
        
    }

    return 0;
}