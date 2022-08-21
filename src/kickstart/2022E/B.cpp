#include <bits/stdc++.h>

using namespace std;
const int maxn = 100000 + 100;
int a[maxn];
int b[maxn];
int main() {
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n;i ++) {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        b[0] = -1;
        printf("Case #%d: ",kase);
        for(int i = 1; i <= n; i++) {
            int x = upper_bound(b + 1, b + 1 + n, 2 * a[i]) - b;
            x--;
            if(b[x] == a[i]) x--;
            printf("%d ", b[x]);

        }
        printf("\n");
    }
    
    return 0;
}