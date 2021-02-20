#include <iostream>

using namespace std;

int query(int l, int r) {
    int res;
    cout << "? " << l << " " << r << endl;
    cout.flush();
    cin >> res;
    return res;
}

int main() {
    int n;
    cin >> n;

    int t = query(1, n);

    if (t == 1 || query(1, t) != t) {
        //在t右边找
        int l = t + 1, r = n;
        int m;
        while (l < r) {
            m = (l + r) >> 1;
            if (query(t, m) == t) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        cout << "! " << l << endl;
    } else {
        //在t左边找
        int l = 1, r = t - 1;
        int m;
        while (l < r) {
            m = (l + r + 1) >> 1;

            if (query(m, t) == t) {
                l = m;
            } else {
                r = m - 1;
            }
            
        }
        cout << "! " << l << endl;
    }

    return 0;
}