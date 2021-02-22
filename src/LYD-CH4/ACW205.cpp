#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;
const int P = 10000;

void mul(int a[2], int b[2][2]) {
    int c[2];
    c[0] = (a[0] * b[0][0] % P + a[1] * b[1][0] % P) % P;
    c[1] = (a[0] * b[0][1] % P + a[1] * b[1][1] % P) % P;
    a[0] = c[0];
    a[1] = c[1];
}

void mulself(int a[2][2]) {
    int c[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++)
                c[i][j] = (c[i][j] + a[i][k] * a[k][j] % P) % P;
        }
    for(int i = 0; i < 2; i++)
        for(int j = 0;j < 2;j++)
            a[i][j] = c[i][j];
}

int main() {

    int n;
    while (cin >> n && n != -1) {
        int f[2] = {0, 1};
        int a[2][2] = {{0, 1},
                       {1, 1}};

        while (n) {
            if (n & 1)
                mul(f, a);
            n >>= 1;
            mulself(a);
            
        }
        cout << f[0] << endl;
    }

    return 0;
}