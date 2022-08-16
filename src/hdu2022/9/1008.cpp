#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool flag[10000 + 10];
int primes[10000], tot;
LL f[100000 + 100];
int lowbit(int x) {
    return x & -x;
}
int lg2[100000 + 100];

void init() {
    int n = 10000;
    for(int i = 2; i <= n; i++) {
        if(!flag[i]) {
            primes[++tot] = i;
        }
        for(int j = 1; j <= tot && i * primes[j] <= n; j++) {
            flag[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }

    lg2[1] = 0;
    for(int i = 2; i <= 100000; i++) {
        lg2[i] = lg2[i >> 1] + 1;
    }
}




int main() {
    init();

    int n, q;
    scanf("%d%d", &n, &q);

    while(q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        if(__gcd(u, v) == 1) {
            printf("%d %d\n", 1, 1);
            continue;
        }

        vector<int> p;
        int cnt = 0;
        cnt += __gcd(u, v) == 2;
        
        for(int i = 1; i <= tot; i++) {
            int t = primes[i];
            if(1ll * t * t > u && 1ll * t * t > v) break;
            if(u % t == 0 || v % t == 0) {
                p.push_back(t);
                while(u % t == 0) u /= t;
                while(v % t == 0) v /= t;
            }
        }
        if(u > 1) p.push_back(u);
        if(v > 1) p.push_back(v);

        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());

        // for(int y : p) printf("%d ", y);
        // printf("\n");

        int k = p.size();

        f[0] = 1;
        
        cnt += n;
        for(int S = 1; S < (1 << k); S++) {
            int lb = lowbit(S);
            int t = lg2[lb];
            if(f[S^lb] * p[t] > n) {
                f[S] = n + 1;
            }else f[S] = -f[S^lb] * p[t];
            cnt += n / f[S];
        }
        // for(int S = 0; S < (1 << k); S ++) {
        //     int t = 1;
        //     int sign = 1;
            
        //     for(int i = 0; i < k; i++) {
        //         if(S >> i & 1) {
        //             sign = -sign;
        //             t = t * p[i];
        //             if(t > n) break;
        //         }
        //     }
        //     if(t > n) continue;
        //     cnt += sign * (n / t);
        // }


        printf("%d %d\n", 2, cnt);
    }


    return 0;
}