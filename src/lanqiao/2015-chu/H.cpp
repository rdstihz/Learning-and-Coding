#include <cstring>
#include <iostream>

using namespace std;
typedef long long LL;
const int N = 6;
const LL P = 1e9 + 7;

struct Matrix {
    int n, m;
    LL d[N][N];
    Matrix(int n, int m) {
        this->n = n;
        this->m = m;
        memset(d, 0, sizeof(d));
    }
};

Matrix operator*(const Matrix& A, const Matrix& B) {
    int n = A.n, m = A.m, l = B.m;
    Matrix res(n, l);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            res.d[i][j] = 0;
            for (int k = 0; k < m; k++) {
                res.d[i][j] = (res.d[i][j] + A.d[i][k] * B.d[k][j]) % P;
            }
        }
    }
    return res;
}

const int ops[] = {0, 4, 5, 6, 1, 2, 3};

Matrix mat_pow(Matrix a, int b) {
    Matrix res(N, N);
    for (int i = 0; i < N; i++)
        res.d[i][i] = 1;

    while (b) {
        if (b & 1)
            res = res * a;
        b >>= 1;
        a = a * a;
    }
    return res;
}

LL pow_mod(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % P;
        b >>= 1;
        a = (a * a) % P;
    }
    return res;
}

int main() {
    int n, m;

    while (cin >> n >> m) {
        Matrix p(N, N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                p.d[i][j] = 1;
        int a, b;
        for (int i = 1; i <= m; i++) {
            cin >> a >> b;
            p.d[a - 1][ops[b] - 1] = 0;
            p.d[b - 1][ops[a] - 1] = 0;
        }

        Matrix ans(1, 6);
        for (int i = 0; i < N; i++) {
            ans.d[0][i] = 1;
        }

        p = mat_pow(p, n - 1);
        ans = ans * p;
        LL res = 0;

        for (int i = 0; i < N; i++)
            res = (res + ans.d[0][i]) % P;

        res = (res * pow_mod(4, n)) % P;
        cout << res << endl;
    }

    return 0;
}