#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn = 110;
const LL P = 1e9 + 7;

LL a[maxn][maxn];

LL read() {
    LL x = 0;
    char c = getchar();
    int flag = 1;
    while((c < '0' || c > '9') && c != '-') c = getchar();
    if(c == '-') {
        flag = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        x %= P;
        c = getchar();
    }
    return (x * flag % P + P) % P;
}

LL pow_mod(LL a, LL b, LL p) {
    LL res = 1;
    while(b) {
        if(b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res % p;
}

void solve() {
    int n = read();
    LL res0 = read();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = read();
    
    for(int i = 1; i <= n; i++) {
        int j = i;
        while(a[i][j] == 0)
            j++;
        
        for(int k = 1; k <= n; k++)
            swap(a[i][k], a[j][k]);
        
        for(j = i + 1; j <= n; j++) {
            LL d = a[j][i] * pow_mod(a[i][i], P - 2, P) % P;
            for(int k = i; k <= n; k++) {
                a[j][k] = (a[j][k] + P - a[i][k] * d % P) % P;
            }
        }

    }

    LL res = 1;
    for(int i = 1; i <= n; i++)
        res = res * a[i][i] % P;
    
    printf("%c\n", res == res0 ? '+' : '-');

}

int main() {
    int T;
    T = read();
    while(T--)
        solve();

    return 0;
}