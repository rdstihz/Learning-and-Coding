#include <iostream>

using namespace std;

const int maxn = 600000 + 100;
const int B = 10000;

bool flag[maxn * 2];
int prime[maxn * 2], tot;
int p[maxn * 2];

void get_prime(int N) {
    tot = 0;
    flag[1] = 1;

    for (int i = 2; i <= N; i++) {
        if (!flag[i]) prime[++tot] = i;
        for (int j = 1; i * prime[j] <= N; j++) {
            flag[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }

}

int get(int n, int p) {
    int s = 0;
    while (n) {
        s += n / p;
        n /= p;
    }
    return s;
}

int res[100000];

void muli(int x) {
    int t = 0;
    for (int i = 1; i <= res[0]; i++) {
        res[i] = res[i] * x + t;
        t = res[i] / B;
        res[i] %= B;
    }
    while (t) {
        res[++res[0]] = t % B;
        t /= B;
    }
}

int main() {

    int n;
    cin >> n;
    get_prime(2 * n);

    for (int i = 1; i <= tot; i++) {
        p[i] = get(2 * n, prime[i]) - get(n, prime[i]) * 2;
    }

    int k = n + 1;
    for (int i = 1; i <= tot; i++) {
        while (k % prime[i] == 0 && k > 1) {
            p[i]--;
            k /= prime[i];
        }
    }

//    for(int i = 1; i <= tot;i ++) {
//        cout << prime[i] << " " << p[i] << endl;
//    }

    res[0] = res[1] = 1;

    for (int i = 1; i <= tot; i++) {
        for (int j = 1; j <= p[i]; j++)
            muli(prime[i]);
    }

    printf("%d", res[res[0]]);

    for (int i = res[0] - 1; i; i--)
        printf("%04d", res[i]);
    printf("\n");

    return 0;
}
