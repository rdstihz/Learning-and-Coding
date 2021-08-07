#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;
int a[maxn];
int n;
int tot;
int build_tree(int L, int R) {
    //printf("%d %d\n", L, R);
    tot++; 
    if (L == R) {
        return tot;
    }

    if (R - L == 1) {
        build_tree(L, L);
        build_tree(R, R);
    } else {
        int B = L + (R - L + 2) / 3 - 1;
        int C = (B + R) / 2;
        //printf("%d %d %d %d\n", L, B, C, R);
        build_tree(L, B);
        build_tree(B + 1, C);
        build_tree(C + 1, R);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        tot = 0;
        build_tree(1, n);
        printf("%d\n", tot);
    }
    return 0;
}