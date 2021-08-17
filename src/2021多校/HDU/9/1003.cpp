#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PII;
const int maxn = 5000 + 10;

int b[maxn];

PII a[maxn];
int best[maxn], worst[maxn];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", b + i);
        }

        sort(a + 1, a + 1 + n, greater<PII>());

        for (int i = 1; i <= n; i++) {
            int t = 2, j = i - 1;
            for (; j >= 1; j--) {
                while (t <= n && a[j].first + b[t] > a[i].first + b[1])
                    t++;
                if (t > n) {
                    break;
                }
                t++;
            }
            best[a[i].second] = j + 1;
        }

        for (int i = n; i >= 1; i--) {
            int t = n - 1, j = i + 1;
            for (; j <= n; j++) {
                while (t >= 1 && a[j].first + b[t] <= a[i].first + b[n])
                    t--;
                if (t < 1)
                    break;
                t--;
            }
            worst[a[i].second] = j - 1;
        }

        for (int i = 2; i <= n; i++) {
            if (a[i].first == a[i - 1].first)
                worst[a[i].second] = worst[a[i - 1].second];
        }

        for (int i = 1; i <= n; i++)
            printf("%d %d\n", best[i], worst[i]);
    }
    return 0;
}