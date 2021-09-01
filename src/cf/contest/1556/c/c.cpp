/*
    Created by rdstihz at 2021-08-29 23:06:12
*/

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int maxn = 2000 + 10;
int a[maxn];
LL l[maxn], r[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    n /= 2;
    for (int i = 1; i <= n; i++)
        l[i] = a[i * 2 - 1], r[i] = a[i * 2];

    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res += min(l[i], r[i]);
        LL cur = r[i] - l[i];
        LL buff = 0; //
        for (int j = i - 1; j >= 1 && cur >= 0; j--) {
            if (r[j] > l[j]) {
                buff += r[j] - l[j];
                continue;
            }
            LL d = l[j] - r[j];
            LL k = min(buff, d);
            buff -= k, d -= k;
            if (buff == 0) {
                res += min(cur, d) + 1;
                cur -= d;
            }
        }
    }
    printf("%lld\n", res);
    return 0;
}