#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000;

vector<int> cur;

void print() {
    cout << cur[0];

    for (int i = 1; i < cur.size(); i++)
        cout << "." << cur[i];
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cur.resize(0);
        int n;
        cin >> n;

        int a;

        for (int i = 1; i <= n; i++) {
            cin >> a;

            if (a == 1)
                cur.push_back(a);
            else {
                for (int i = cur.size() - 1; i >= 0; i--) {
                    if (cur[i] == a - 1) {
                        cur.resize(i);
                        cur.push_back(a);
                        break;
                    }
                }
            }
            print();
        }
    }

    return 0;
}