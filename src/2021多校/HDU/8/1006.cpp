#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int read() {
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
const int N = 10000000;
int f[N + 5], prime[N + 5], sg[N + 5];
int main() {

    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (!f[i]) prime[++cnt] = i, sg[i] = 1;
        for (int j = 1; j <= cnt; j++) {
            int t = i * prime[j];
            if (t > N) break;
            sg[t] = sg[i] + 1;
            f[t] = 1;
            if (i % prime[j] == 0) {
                
            }
        }
    }
    int T = read();
    while (T--) {
        int n = read(), ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = read();
            ans ^= sg[x];
        }
        if (ans == 0)
            puts("Bob");
        else
            puts("Alice");
    }
    return 0;
}