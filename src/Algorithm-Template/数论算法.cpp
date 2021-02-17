#include <bits/stdc++.h>

using namespace std;

//GCD: 欧几里德算法，计算a,b的最大公约数,复杂度O(log(a + b))
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

//数论分块, 计算 k / 1 + k / 2 + k / 3 + ... + k / n  (除法为整除)
//复杂度O(sqrt(k))
int nt_block(int n, int k) {
    int ans = 0;
    for (int x = 1, gx; x <= n; x = gx + 1) {
        gx = k / x ? min(k / (k / x), n) : n;
        ans += (k / x) * (gx - x + 1);
    }
}

//线性筛素数
//复杂度 O(N)
const int N = 10000;
int prime[N + 10], tot;
bool flag[N + 10];
void get_primes() {
    flag[1] = true;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            prime[++tot] = i;
        }
        for (int j = 1; j <= tot && i * prime[j] <= N; j++) {
            flag[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

//阶乘分解
//复杂度O(nlogn)
int p[10000], c[10000];
void divide_prod(int n) {
    get_primes();
    for (int i = 1; i <= tot && prime[i] <= n; i++) {
        int s = n;
        while (s) {
            c[i] += s / prime[i];
            s /= prime[i];
        }
    }
}

//计算欧拉函数
int phi(int n) {
    int ans = n;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            ans = ans / i * (i - 1);
        while (n % i == 0)
            n /= i;
    }
    if(n > 1)
        ans = ans / n * (n - 1);
    return ans;
}

int main() {
    get_primes();
    for (int i = 1; i <= 20; i++)
        cout << prime[i] << " ";
    cout << endl;
}