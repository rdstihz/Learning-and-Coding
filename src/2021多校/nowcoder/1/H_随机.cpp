#include <bits/stdc++.h>

using namespace std;

const int maxn = 500000 + 100;
int a[maxn];
bool del[maxn];
int cnt[maxn];
bool used[maxn];
int n;
int m=0;

bool check(int x) {
    ++m;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i] % x] ==m) return false;
        cnt[a[i] % x]=m;
    }
    return true;
}

int main() {

    scanf("%d", &n);

    srand((unsigned)time(NULL));

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	mt19937 rand_num(seed);  // 大随机数
	uniform_int_distribution<long long> dist(0, n - 1);  // 给定范围
    
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    random_shuffle(a , a + n);
    int T = 4500000;

    while (T--) {
        int x = dist(rand_num) % n;
        int y = dist(rand_num) % n;
        int d = abs(a[x] - a[y]);
        if(del[d]) continue;
        //used1[d] = true;
        for (int i = 1; i * i <= d; i++) {
            if (d % i == 0) del[i] = del[d / i] = true;
        }
    }

    for (int i = n;; i++) {
        if (del[i]) continue;
        if (check(i)) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}