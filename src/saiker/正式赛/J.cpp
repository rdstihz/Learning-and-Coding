#include <iostream>

using namespace std;

int main() {
    int A, B, a, b;
    cin >> A >> B >> a >> b;

    int x = A / (2 * a - 1) + (A % (2 * a - 1) >= a);
    int y = B / (2 * b - 1) + (B % (2 * b - 1) >= b);
    cout << x * y << endl;
    return 0;
}