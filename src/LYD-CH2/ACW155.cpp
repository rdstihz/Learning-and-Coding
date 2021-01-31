#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

int N;
int t, m, p;

queue<PII> waits;                                     // 内存 ， 时间
set<PII> runs;                                        // 正在运行, 首地址，长度
priority_queue<PII, vector<PII>, greater<PII>> endts; //结束时间，内存地址

int ans, cnt;

bool work(int t, int m, int p) {

    for (auto it = runs.begin(); it != runs.end(); it++) {
        auto jt = it;
        jt++;

        if(jt == runs.end()) break;
        
        int start = it->first + it -> second;
        if(m <= jt->first - start) {
            runs.insert(make_pair( start,m));
            endts.push(make_pair(t + p,start));
            return true;
        }

    }

    return false;
}

void finish(int t) {

    while (endts.size() && endts.top().first <= t) {
        int f = endts.top().first;
        ans = f;
        while (endts.size() && endts.top().first == f) {
            auto it = runs.lower_bound(make_pair(endts.top().second, 0));
            runs.erase(it);
            endts.pop();
        }

        while (waits.size()) {
            if (work(f, waits.front().first, waits.front().second)) {
                waits.pop();
            } else {
                break;
            }
        }
    }
}

int main() {

    cin >> N;
    runs.insert(make_pair(-1, 1));
    runs.insert(make_pair(N, 1));

    while (cin >> t >> m >> p, t || m || p) {
        finish(t);
        if (!work(t, m, p)) {
            cnt++;
            waits.push(make_pair(m, p));
        }
    }

    finish(2e9);

    cout << ans << endl;
    cout << cnt << endl;

    return 0;
}
