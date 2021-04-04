#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100000 + 100;

typedef pair<int, int> PII;

PII a[maxn];

vector<int> p[maxn];

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    for (int i = 1; i <= m; i++)
        cin >> a[i].first >> a[i].second;

    sort(a + 1, a + 1 + m);

    for (int i = 1; i <= m; i++) {
        p[a[i].second].push_back(a[i].first);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int last = 0;
        int pr = 0;
        bool inq = false;
        for (int j = 0; j < p[i].size(); j++) {
            //下跌
            if (p[i][j] > last){
                pr -= p[i][j] - last - 1;
                if(pr < 0) pr = 0;
            }
                
            if (pr <= 3) inq = false;
            pr += 2;
            if (pr > 5) inq = true;
            last = p[i][j];
        }

        if (last < t) {
            pr -= t - last;
            if(pr < 0) pr = 0;
            if (pr <= 3) inq = false;
        }

        if (inq) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}