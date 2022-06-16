/*
    Created by godlei at 2022-06-12 22:42:00
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 200000 + 100;

LL a[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    
    sort(a + 1, a + 1 + n);
    
    for(int i = 2; i <= n; i++)
        a[i] += a[i - 1];
    

    while(m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int st = n - x + 1;
        int ed = st + y - 1;
        printf("%lld\n", a[ed] - a[st - 1]);
    }



    return 0;
}