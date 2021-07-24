#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int n, m, a, b, c, d, p;
LL V;
int nxt() {
    V = (V * V * b + V * c + d) % p;
    return V;
}

int main() {
    scanf("%d%d%d%d%d%d%d", &n, &m, &a, &b, &c, &d, &p);
    V = a;

    return 0;
}