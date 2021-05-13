#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int maxn = 300000 + 100;
const double pi = acos(-1);

struct Complex {
    double x, y;

    Complex() {
        x = y = 0;
    }
    Complex(double x, double y) : x(x), y(y) {}

    Complex operator+(const Complex& b) const {
        return Complex(x + b.x, y + b.y);
    }

    Complex operator-(const Complex& b) const {
        return Complex(x - b.x, y - b.y);
    }

    Complex operator*(const Complex& b) const {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
} a[maxn], b[maxn];

int rev[maxn];

int n, m, N, l;

void fft(Complex* A, int N, int type) {

    for (int i = 0; i < N; i++)
        if (rev[i] < i)
            swap(A[i], A[rev[i]]);

    for (int len = 2; len <= N; len <<= 1) {
        int m = len >> 1;
        Complex wn(cos(2 * pi / len), type * sin(2 * pi / len));
        for (int j = 0; j < N; j += len) {
            Complex w(1, 0);

            for (int i = 0; i < m; i++) {
                Complex u = A[j + i];
                Complex v = A[j + i + m];

                A[j + i] = u + w * v;
                A[j + i + m] = u - w * v;

                w = w * wn;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i <= n; i++)
        scanf("%lf", &a[i].x);
    for (int i = 0; i <= m; i++)
        scanf("%lf", &b[i].x);

    N = 1, l = 0;

    while (N < n + m + 1) {
        N <<= 1;
        l++;
    }
    for (int i = 0; i < N; i++)
        rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);
    fft(a, N, 1);
    fft(b, N, 1);

    for (int i = 0; i < N; i++)
        a[i] = a[i] * b[i];

    fft(a, N, -1);

    for (int i = 0; i <= n + m; i++)
        printf("%d ", (int)(a[i].x / N + 0.5));

    return 0;
}
