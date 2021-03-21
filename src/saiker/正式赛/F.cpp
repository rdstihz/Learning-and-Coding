#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;

char s[maxn];

int main() {

    while (cin.getline(s + 1, 200)) {
        int p = 1;
        int n = strlen(s + 1);
        string ans;
        stringstream ss(ans);

        

        while (p <= n) {
            int r = p;
            if (isalpha(s[p])) {
                //扣出一个单词
                while (r <= n && isalpha(s[r]))
                    r++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
