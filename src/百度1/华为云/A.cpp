#include <bits/stdc++.h>

using namespace std;

const int maxn = 500000 + 100;
int a[maxn], b[maxn];

int lowbit(int x) {
    return x & -x;
}

long long cnt1[60], cnt2[60];

unordered_map<int, int> lg2;
void init() {
    for (int i = 0; i <= 30; i++)
        lg2[1 << i] = i;
}

int main() {
    int T;
    scanf("%d", &T);
    init();
    while (T--) {
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            cnt1[lg2[a[i]]]++;
        }
        int t;
        for (int i = 1; i <= m; i++) {
            scanf("%d", b + i);
            while (b[i]) {
                int t = lowbit(b[i]);
                cnt2[lg2[t]]++;
                b[i] -= t;
            }
        }

        //for (int i = 0; i < 5; i++)
        //    printf("%d %d\n", cnt1[i], cnt2[i]);

        bool flag = true;
        for (int i = 30; i >= 0; i--) {
            if (cnt1[i] > cnt2[i]) {
                flag = false;
                break;
            }
            cnt2[i] -= cnt1[i];
            if (i) cnt2[i - 1] += 2 * cnt2[i];
        }
        printf("%s\n", flag ? "Yes"
                            : "No");
    }
    return 0;
}