#include <bits/stdc++.h>

using namespace std;

const int P = 4933;

int pow_mod(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

int main() {
    int n, m, k, a, l;

    scanf("%d%d%d%d%d", &n, &m, &k, &a, &l);
    int t = 1;

    while (k--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 0) continue;
        t = (t * (z - y) % P) * pow_mod(z, P - 2, P) % P;
    }
    t = (t + a) % P;
    printf("%d\n", t);
    return 0;
}

/*
5 3 2 1 5
2 2 3
3 3 4
*/
