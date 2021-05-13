#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

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
int get_euler(int n) {
    int ans = n;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            ans = ans / i * (i - 1);
        while (n % i == 0)
            n /= i;
    }
    if (n > 1)
        ans = ans / n * (n - 1);
    return ans;
}

//线性筛积性函数 （欧拉函数）
int phi[N + 10];
void get_euler() {
    flag[1] = true;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            prime[++tot] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= tot && i * prime[j] <= N; j++) {
            flag[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}

//扩展欧几里得算法 exgcd
//求方程 ax + by = gcd(a,b) 的一组解(x0,y0)
int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        int d = exgcd(b, a % b, y, x);
        y -= x * (a / b);
        return d;
    }
}

//Baby Step, Giant Step算法:
//求解不定方程 a^x = b (mod p)
//x = i * t - j  ( 1 <= i <= t,  0 <= j <= t ) (t ^ 2 >= p) 
//注意i不能从0开始，否则会产生负数解
//j必须取到t， 否则可能漏解 x = 0
//a^(i*t) = b*a^j (mod p)
LL bsgs(LL a, LL b, LL p) {
    b %= p;
    unordered_map<LL, LL> hash;
    LL t = sqrt(p) + 1;
    LL x = 1;
    for (LL j = 0; j < t; j++) {
        LL val = b * x % p;
        hash[val] = j;
        x = x * a % p;
    }
    hash[b * x % p] = t;
    a = x;
    for (LL i = 1; i <= t; i++) {
        if (hash.count(x)) {
            return i * t - hash[x];
        }
        x = x * a % p;
    }
    return -1;
}

int main() {
    LL a, b, p;

    while(cin >> p >> a >> b) {
        LL x = bsgs(a,b,p);
        if(x == -1)
            cout << "no solution" << endl;
        else
            cout << x << endl;
    }
}