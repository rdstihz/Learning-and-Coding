#include <bits/stdc++.h>

using namespace std;

int a[1000];
bool ended;
int n, k;
void add() {
    a[1]++;
    int i = 1;
    while (i <= n && a[i] >= (1 << k)) {
        a[i] = 0;
        a[i + 1]++;
        i++;
    }
    if (i > n) ended = true;
}

int main() {
    scanf("%d%d", &n, &k);
    int ans = 0;
    ended = false;
    while (!ended) {
        int ands = (1 << k) - 1;
        int xors = 0;
        for (int i = 1; i <= n; i++) {
            ands &= a[i];
            xors ^= a[i];
        }
        if (ands >= xors) ans++;
        add();
    }
    printf("%d\n", ans);

    main();
    return 0;
}