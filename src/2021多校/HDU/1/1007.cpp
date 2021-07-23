#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL P = 998244353;
const int hashsize = 1000000;
struct Hash {

    int fir[hashsize], nxt[hashsize];
    LL key[hashsize], val[hashsize];
    int tot;
    int H(LL x) {
        return x % hashsize;
    }

    void init() {
        tot = 0;
        memset(fir, 0, sizeof(fir));
    }

    void insert(LL x, LL v) {
        int h = H(x);
        for (int i = fir[h]; i; i = nxt[i]) {
            if (key[i] == x) {
                val[i] = v;
                return;
            }
        }
        tot++;
        key[tot] = x, val[tot] = v;
        nxt[tot] = fir[h], fir[h] = tot;
    }

    LL query(LL x) {
        int h = H(x);
        for (int i = fir[h]; i; i = nxt[i]) {
            if (key[i] == x) return val[i];
        }
        return -1;
    }
} T;

LL bsgs(LL a, LL b, LL p) {
    b %= p;
    T.init();
    //unordered_map<LL, LL> hash;
    LL t = sqrt(p) + 1;
    LL x = 1;
    for (LL j = 0; j < t; j++) {
        LL val = b * x % p;
        //hash[val] = j;
        T.insert(val, j);
        x = x * a % p;
    }
    //hash[b * x % p] = t;
    T.insert(b * x % p, t);
    a = x;
    LL q;
    for (LL i = 1; i <= t; i++) {
        /*
        if (hash.count(x)) {
            return i * t - hash[x];
        }*/
        if ((q = T.query(x)) != -1) {
            return i * t - q;
        }
        x = x * a % p;
    }
    return -1;
}

int main1() {
    T.init();

    cout << T.query(2) << endl;
    T.insert(2, 2);
    T.insert(9999999990, 13);
    cout << T.query(2) << endl;
    cout << T.query(9999999990) << endl;
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        LL n, x;
        scanf("%lld%lld", &n, &x);
        LL b1 = (x * n % P + (n - 1)) % P;
        LL b2 = (x * n % P + P - (n - 1)) % P;

        LL t1 = bsgs(n - 1, b1, P);
        LL t2 = bsgs(n - 1, b2, P);

        if (t1 % 2 == 1 && t2 % 2 == 0)
            printf("%lld\n", min(t1, t2));
        else if (t1 % 2 == 1)
            printf("%lld\n", t1);
        else if (t2 % 2 == 0)
            printf("%lld\n", t2);
        else
            printf("-1\n");
    }
    return 0;
}