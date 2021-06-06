#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000 + 100;

int a[maxn];
vector<int> nums;

int main() {

    int T;

    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        nums.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            nums.push_back(a[i]);
        }

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
        }



        bool flag = false;
        for (int i = 2; i <= n; i++) {
            int x = a[i - 1];
            int y = a[i];
            
        }

        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}