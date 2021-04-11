#include <iostream>

using namespace std;

bool check(int x) {
    int c0 = 0;
    int c1 = 0;

    while (x) {
        if (x & 1) {
            c1++;
        } else {
            c0++;
        }
        x >>= 1;
    }
    return c1 <= c0;
}



int main() {

    int ans = 0;

    for (int i = 1; i <= 20210411; i++) {

        if (check(i))
            ans++;
    }
    cout << ans << endl;

    return 0;
}