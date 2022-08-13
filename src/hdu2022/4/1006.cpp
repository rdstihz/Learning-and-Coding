#include <bits/stdc++.h>


using namespace std;

void solve() {
    int n;
    double ans1 = 0, ans2 = 0;
    int S = 0;

    scanf("%d", &n);
    int v;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v);
        S += v;

        if(ans1 < 100) ans1 += v;
        else if(ans1 < 200) ans1 += 0.8 * v;
        else ans1 += 0.5 * v;

    }

    if(S <= 100) {
        ans2 = S;
    }else if(S <= 100 + 100 / 0.8) {
        ans2 = 100 + (S - 100) * 0.8;;
    }else {
        ans2 = 200 + (S - 100 - 125) * 0.5;
    }

    printf("%.3lf %.3lf\n", ans2, ans1);
}


int main() {
    int T;
    scanf("%d", &T);
    while(T--)
        solve();

    return 0;
}