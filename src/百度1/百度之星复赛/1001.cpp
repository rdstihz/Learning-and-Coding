#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    if (n == 1)
        puts("No!");
    else if (n == 2)
        puts(k == 1 ? "Yes!" : "No!");
    else
        puts(n == k || (k & 1) ? "Yes!" : "No!");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}