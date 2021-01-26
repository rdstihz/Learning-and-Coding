#include <cstdio>

const int maxn = 100000 + 100;

int l[maxn];
int n, k;

bool check(int x){
    if(x == 0) return true;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
        cnt += l[i]/x;
    return cnt >= k;
}

int main() {
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++)
        scanf("%d", l + i);

    int L = 0, R = 1000000000;
    int M;

    while(L < R) {
        M = L+R >> 1;
        if(!check(M)) R = M;
        else L = M + 1;
    }
    printf("%d\n",L-1);
    return 0;
}