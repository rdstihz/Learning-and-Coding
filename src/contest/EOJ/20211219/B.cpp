#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
int h[maxn], v[maxn];

int main() {
    int S, H, n;
    scanf("%d%d", &S, &H);
    
    scanf("%d", &n);
    int s = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", h + i, v + i);
        s += v[i];
    }

    double ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += 1.0 * (H - h[i]) / s;
        H = h[i];
        s -= v[i];
    }
    printf("%.10f\n", ans * S);

    return 0;
}