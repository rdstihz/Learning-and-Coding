#include <bits/stdc++.h>

using namespace std;

unordered_map<string, bool> M;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
    
        M.clear();
        for (int i = 0; i < n; i++) {
            M[s.substr(i, 1)] = true;
            if (i < n - 1) M[s.substr(i, 2)] = true;
            if (i < n - 2) M[s.substr(i, 3)] = true;
            //if (i < n - 3) M[s.substr(i, 4)] = true;
        }
        string cur = "";
        // cout << cur + 'a' + 'b' << endl;
        // cout << M.count(cur + 'a') << endl;

        // len = 1
        bool ok = false;
        for (char a = 'a'; a <= 'z' && !ok; a++) {
            if (!M.count(cur + a)) {
                cout << a << endl;
                ok = true;
                break;
            }
        }

        // len = 2
        for (char a = 'a'; a <= 'z' && !ok; a++) {
            for (char b = 'a'; b <= 'z' && !ok; b++) {
                if (!M.count(cur + a + b)) {
                    cout << a << b << endl;
                    ok = true;
                }
            }
        }

        //len = 3
        for (char a = 'a'; a <= 'z' && !ok; a++) {
            for (char b = 'a'; b <= 'z' && !ok; b++) {
                for (char c = 'a'; c <= 'z' && !ok; c++) {
                    if (!M.count(cur + a + b + c)) {
                        cout << a << b << c << endl;
                        ok = true;
                    }
                }
            }
        }
    }

    return 0;
}