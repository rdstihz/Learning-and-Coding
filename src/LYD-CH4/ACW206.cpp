#include <cctype>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<LL> vec;
typedef vector<vec> mat;

int n, m, t, act;
char M[12][12];
char ops[12][12], len[12];

mat A, B[61];

inline int id(int x, int y) {
    int res = (x - 1) * m + y;
    if (res > n * m) {
        cout << "!!!" << " " << x << " " << y << endl;
        exit(0);
    }
    return res;
}

void mul(mat& A, const mat& B) {
    mat res(A.size(), vec(B[0].size()));

    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < B[0].size(); j++) {
            res[i][j] = 0;
            for (int k = 0; k < B.size(); k++) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    A = res;
}

int main() {

    cin >> n >> m >> t >> act;

    for (int i = 1; i <= n; i++)
        cin >> (M[i] + 1);

    for (int i = 0; i < act; i++) {
        cin >> ops[i];
        len[i] = strlen(ops[i]);
    }

    int N = n * m + 1;

    for (int i = 0; i < 60; i++)
        B[i].resize(N, vec(N));

    for (int i = 0; i < 60; i++) {
        //cout << i << endl;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= m; y++) {
                char op = ops[M[x][y] - '0'][i % len[M[x][y] - '0']];
                if (isdigit(op)) {
                    B[i][id(x, y)][id(x, y)] = 1;
                    B[i][0][id(x, y)] = op - '0';
                } else if (op == 'N' && x > 1)
                    B[i][id(x, y)][id(x - 1, y)] = 1;
                else if (op == 'S' && x < n)
                    B[i][id(x, y)][id(x + 1, y)] = 1;
                else if (op == 'W' && y > 1)
                    B[i][id(x, y)][id(x, y - 1)] = 1;
                else if (op == 'E' && y < m)
                    B[i][id(x, y)][id(x, y + 1)] = 1;
            }
        }
        B[i][0][0] = 1;
    }

    mat C = B[0];
    for (int i = 1; i < 60; i++)
        mul(C, B[i]);

    int w = t / 60;

    A.resize(1, vec(N));
    A[0][0] = 1;

    while (w) {
        if (w & 1)
            mul(A, C);
        mul(C, C);
        w >>= 1;
    }
    w = t % 60;
    for (int i = 0; i < w; i++)
        mul(A, B[i]);

    LL ans = 0;
    for (int i = 1; i < N; i++)
        ans = max(ans, A[0][i]);
    cout << ans << endl;
    return 0;
}