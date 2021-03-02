#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;
typedef vector<LL> vec;
typedef vector<vec> mat;

const LL P = 1e8;

void mul(const mat& A, const mat& B, mat& C) {
    mat res(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            res[i][j] = 0;
            for (int k = 0; k < B.size(); k++)
                res[i][j] = (res[i][j] + A[i][k] * B[k][j] % P) % P;
        }
    }
    C = res;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n >> m;
    n = gcd(n, m);

    mat f(1, vec(2));
    f[0][0] = 0;
    f[0][1] = 1;

    mat p(2, vec(2));
    p[0][0] = 0;
    p[0][1] = p[1][0] = p[1][1] = 1;

    while (n) {
        if (n & 1) {
            mul(f, p, f);
        }
        mul(p, p, p);
        n >>= 1;
    }
    cout << f[0][0] << endl;
    return 0;
}