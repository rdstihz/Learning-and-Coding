#include <cstdio>

const int maxn = 1000000 + 10;

int a[maxn];
int q[maxn], l, r;

int main() {

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);

    l = r = 0;
    for (int i = 1; i <= n; i++) {
        while (r > l && a[q[r]] > a[i])
            r--;

        if (r > l && i - q[l+1] >= k) l++;
        q[++r] = i;
        if (i >= k) printf("%d ", a[q[l + 1]]);
    }

    printf("\n");
    l = r = 0;
    for (int i = 1; i <= n; i++) {
        while (r > l && a[q[r]] < a[i])
            r--;
        if(r > l && i - q[l+1] >= k) l++; 
        q[++r] = i;
        if(i >= k) printf("%d ",a[q[l+1]]);
    }
    printf("\n");
    return 0;
}