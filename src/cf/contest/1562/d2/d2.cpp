/*
    Created by rdstihz at 2021-08-26 23:24:45
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 300000 + 100;
char s[maxn];
int a[maxn];

vector<int> pos[maxn * 2];

void solve() {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i] == '+' ? 1 : -1;
    for (int i = 2; i <= n; i += 2)
        a[i] = -a[i];
    for (int i = 2; i <= n; i++)
        a[i] += a[i - 1];

    int N = 300010;
    for (int i = -n; i <= n; i++) {
        pos[i + N].clear();
    }
    for (int i = 1; i <= n; i++) {
        pos[a[i] + N].push_back(i);
    }

    int l, r;
    while (q--) {
        scanf("%d%d", &l, &r);
        if (a[r] - a[l - 1] == 0)
            puts("0");
        else {
            int len = r - l + 1;
            if (len % 2 == 0) {
                printf("2\n%d ", l);
                l++;
            } else {
                printf("1\n");
            }
            //int m = (a[r] >= a[l - 1]) ? (a[l - 1] + a[r] + 1) / 2 : (a[l - 1] + a[r]) / 2;
            int delta = a[r] - a[l - 1];
            if (delta < 0)
                delta--;
            else if (delta > 0)
                delta++;
            int m = a[l - 1] + delta / 2;
            int t = *(lower_bound(pos[m + N].begin(), pos[m + N].end(), l));
            printf("%d\n", t);
        }
    }
}

int main() {
    //printf("%d\n", (-9) / 2);
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}