#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 100;
char s[maxn];
char s1[maxn];
int main() {

    cin.getline(s, maxn);

    stringstream ss(s);
    int T;
    ss >> T;
    while(T--) {
        cin.getline(s, maxn);
        stringstream ss(s);

        while(ss >> s1) {
            cout << (char)(s1[0] - 'a' + 'A');
        }

        cout << endl;
    }


    return 0;
}