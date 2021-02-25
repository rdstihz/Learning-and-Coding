#include <iostream>
#include <string>

using namespace std;

int a[7]; //上下左右前后

void roll(int a1, int a2, int a3, int a4) {
    int t = a[a1];
    a[a1] = a[a2];
    a[a2] = a[a3];
    a[a3] = a[a4];
    a[a4] = t;
}

int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        for (int i = 1; i <= 6; i++)
            cin >> a[i];
        string s;
        cin >> s;
        for (char c : s) {
            if (c == 'F')
                roll(1, 6, 2, 5);
            else if (c == 'B')
                roll(1, 5, 2, 6);
            else if (c == 'L')
                roll(1, 4, 2, 3);
            else if (c == 'R')
                roll(1, 3, 2, 4);
        }
        cout << "Case " <<k  << ": " << a[1] << endl;
    }
}