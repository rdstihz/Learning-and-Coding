#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 100;

int a[maxn];
int n, c;


bool check(int x){
    int cnt = 1;
    int last = a[1];

    for(int i = 2;i<=n;i++) {
        if(a[i]- last >= x) {
            cnt ++;
            last = a[i];
        }
    }
    return cnt >= c;
}

int main() {
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a+1,a+1+n);
    int l = 0,r = 1000000000;
    int m;
    while(l < r) {
        m = l + r >> 1;
        if(!check(m)) r = m;
        else l = m + 1;
    }
    printf("%d\n",l-1);

    return 0;
}