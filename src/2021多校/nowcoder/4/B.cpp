#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
double w[maxn];
double B[maxn];
int main() {
    int n;
    double C;
    scanf("%d", &n);
    scanf("%lf", &C);
    double ans2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", w + i);
        ans2 += w[i];
    }

    sort(w + 1, w + 1 + n);
    double ans = C;

    B[0] = 1;
    for (int i = 1; i <= n; i++)
        B[i] = B[i - 1] * 2;
    for (int i = 1; i <= n; i++) {
        ans += w[i] * (1 - B[i - 1] / B[n - 1]);
    }
    printf("%.10f\n", min(ans, ans2));
    return 0;
}