#include <iostream>

using namespace std;

const int N = 1000;

bool flag[N + 10];
int prime[N + 10], phi[N + 10];
int tot;

void init() {
    flag[1] = true;
    phi[1] = 1;

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

int main() {
    init();

    int T;
    cin >> T;
    for(int k = 1; k <= T;k++) {
        int n;
        cin >> n;
        int ans = 3;
        for(int i = 2;i <= n;i++) {
            ans += 2 * phi[i];
        }
        cout << k << " " << n << " " << ans << endl;
    }

    return 0;
}