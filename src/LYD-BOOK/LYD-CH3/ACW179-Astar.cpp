#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, string> PIS;
const int N = 9;

int f(const string& s) {
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] != 'x') {
            int t = s[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    }
    return res;
}

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const char op[] = "urdl";

string bfs(string start) {
    unordered_map<string, int> dist;
    unordered_map<string, bool> vis;
    unordered_map<string, pair<string, char>> pre;
    priority_queue<PIS, vector<PIS>, greater<PIS>> Q;

    string end = "12345678x";

    Q.push(make_pair(f(start), start));
    dist[start] = 0;

    while (Q.size()) {
        string state = Q.top().second;
        Q.pop();

        if (vis.count(state)) continue;
        vis[state] = true;

        if (state == end) {
            string res = "";
            while (state != start) {
                res += pre[state].second;
                state = pre[state].first;
            }
            reverse(res.begin(), res.end());
            return res;
        }

        int step = dist[state];
        int x, y;
        for (int i = 0; i < N; i++)
            if (state[i] == 'x') {
                x = i / 3;
                y = i % 3;
                break;
            }
        string bak = state;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < 3 && yy >= 0 && yy < 3) {

                swap(state[3 * x + y], state[3 * xx + yy]);
                if (!dist.count(state) || dist[state] > step + 1) {
                    dist[state] = step + 1;
                    pre[state] = make_pair(bak, op[i]);
                    Q.push(make_pair(dist[state] + f(state), state));
                }
                swap(state[3 * x + y], state[3 * xx + yy]);
            }
        }
    }
}

int main() {

    string start, seq;
    char c;

    for (int i = 0; i < N; i++) {
        cin >> c;
        start += c;
        if (c != 'x')
            seq += c;
    }

    int cnt = 0;
    for (int i = 0; i < 8; i++)
        for (int j = i + 1; j < 8; j++) {
            if (seq[i] > seq[j])
                cnt++;
        }
    if (cnt % 2) {
        cout << "unsolvable" << endl;
    } else {
        cout << bfs(start) << endl;
    }

    return 0;
}