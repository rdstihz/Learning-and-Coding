#include <bits/stdc++.h>

using namespace std;

int main() {
    srand((unsigned)time(NULL));
    freopen("in", "w", stdout);
    int T;
    T = 10;

    printf("%d\n", T);
    while (T--) {
        int a = rand() % 2000 - 1000;
        int b = rand() % 2000000 - 1000000;
        int c = rand() % 2000000 - 1000000;
        int d = rand() % 2000000 - 1000000;
        int n = rand() % 1000000 + 1;
        printf("%d %d %d %d %d\n", a, b, c, d, n);
    }

    return 0;
}