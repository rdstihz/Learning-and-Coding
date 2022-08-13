#include <bits/stdc++.h>


using namespace std;

const int maxn = 1000;
const int INF = 0x3f3f3f3f;
int f[maxn];


int main() {

    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    long long n = 990;
    for(int i = 1; i <= n; i++) {
        if(i >= 7) f[i] = min(f[i], f[i - 7] + 1);
        if(i >= 31) f[i] = min(f[i], f[i - 31] + 1);
        //printf("%d %d\n", i, f[i]);
    }

    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%lld", &n);
        if(n <= 179) {
            if(f[n] == INF) printf("-1\n");
            else printf("%d\n", f[n]);
        }else {
            long long q = n / 365;
            int r = n % 365;

            if(r <= 179 && f[r] == INF) {
                r += 365;
                q--;
            }

            printf("%lld\n", q + f[r]);

        }

    }

    return 0;
}