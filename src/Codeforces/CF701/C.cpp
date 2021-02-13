#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long x, y;
        cin >> x >> y;
        long long ans = 0;

        y++; 
        for(long long i = 3,gx;i <= y;i = gx + 1) {
            gx = x / i ? min( x / (x / i), y ) : y;
            ans += (x / i) * (gx - i + 1);
        }

        cout << ans << endl;
    }

    return 0;
}