#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 1000000 + 100;
int a[maxn];

void solve() {
    int n;

    scanf("%d", &n);
    bool flag = false;
    for(int i = 0; i <= n; i++) {
        scanf("%d", a + i);
    }

    LL delta = 1;
    for(int i = 0; i <= n; i++) {
        delta -= a[i];

        if(delta <= 0) {
            flag = true;
            break;
        }
        delta <<= 1;
        if(delta > 1000000) break;
    }

    puts(flag ? "Alice" : "Bob");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--)
        solve();

    return 0;
}