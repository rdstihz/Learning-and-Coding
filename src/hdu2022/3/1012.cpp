#include <bits/stdc++.h>


using namespace std;
const int P = 998244353;
const int maxn = 300000 + 100;

int f[2 * maxn][2];
int pos[maxn][2];

int p[maxn], q[maxn], s[2 * maxn];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", p + i);
        pos[p[i]][0] = i;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", q + i);
        pos[q[i]][1] = i;
    }

    for(int i = 1; i <= 2 * n; i++) {
        scanf("%d", s + i);
    }
    
    f[0][0] = 1;
    for(int i = 1; i <= 2 * n; i++) {
        //f[i-1][0]
        int a = pos[s[i - 1]][0];
        int b = i - 1 - a;
        if(a < i) {
            if(a + 1 <= n && p[a + 1] == s[i]) f[i][0] = (f[i][0] + f[i - 1][0]) % P;
            if(b + 1 <= n && q[b + 1] == s[i]) f[i][1] = (f[i][1] + f[i - 1][0]) % P;
        }
        

        //f[i-1][1]
        b = pos[s[i - 1]][1];
        a = i - 1 - b;

        if(b < i) {
            if(a + 1 <= n && p[a + 1] == s[i]) f[i][0] = (f[i][0] + f[i - 1][1]) % P;
            if(b + 1 <= n && q[b + 1] == s[i]) f[i][1] = (f[i][1] + f[i - 1][1]) % P;
        }

    }

    printf("%d\n", (f[2 * n][0] + f[2 * n][1]) % P);

    for(int i = 0; i <= 2 * n; i++) {
        f[i][0] = f[i][1] = 0;
    }
    
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }

    return 0;
}