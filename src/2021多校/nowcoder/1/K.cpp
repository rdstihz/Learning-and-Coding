#include <bits/stdc++.h>

using namespace std;

const int maxn = 40000 + 100;

int a[maxn];
int b[maxn];
bool used[maxn];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        sort(a, a + n);

        for (int i = 0; i < n; i++) {
            b[i] = -1;
            used[i] = 0;
        }

        int cnt = 0;
        for (int d = 0; d <= n && cnt < n; d++) {
            for (int i = 0; i < n; i++)
                if (!used[i]) {
                    if (a[i] - d >= 0 && b[a[i] - d] == -1) {
                        used[i] = true;
                        b[a[i] - d] = a[i];
                        cnt++;
                    } else if (a[i] + d < n && b[a[i] + d] == -1) {
                        used[i] = true;
                        b[a[i] + d] = a[i];
                        cnt++;
                    }
                }
        }

        for (int i = 0; i < n; i++)
            printf("%d ", b[i]);
        printf("\n");
    }

    return 0;
}