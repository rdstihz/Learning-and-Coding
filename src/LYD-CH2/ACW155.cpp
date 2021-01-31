#include <bits/stdc++.h>

using namespace std;

struct Mem {
    int head, len;
    Mem(int head, int len) : head(head), len(len) {}
    bool operator<(const Mem& phs) const {
        if(head == phs.head) return len < phs.len;
        return head < phs.head;
    }
};
struct Exec {
    int head, len;
    int endtime;
    Exec(int head, int len, int endtime) : head(head), len(len), endtime(endtime) {}
    bool operator<(const Exec& phs) const {
        return endtime < phs.endtime;
    }
};
struct Prog {
    int len;
    int T;
    Prog(int len, int T) : len(len), T(T) {}
};

set<Mem> buff; // 内在缓冲池
set<Exec> run; //运行中
queue<Prog> Q; //队列

const int maxn = 10000 + 10;
int t[maxn], m[maxn], p[maxn];
int n;
int N;

void mergeInsert(Mem temp) {

    Mem a(0, 0);
    Mem b(0, 0);

    for (auto it = buff.begin(); it != buff.end(); it++) {
        if (it->head + it->len == temp.head) {
            temp.head = it->head;
            temp.len += it->len;
            a = *it;
        } else if (temp.head + temp.len == it->head) {
            temp.len += it->len;
            b = *it;
        }
    }
    if (a.len) buff.erase(a);
    if (b.len) buff.erase(b);

    buff.insert(temp);
}

bool work(Prog temp, int curT) {
    auto it = buff.begin();
    while (it != buff.end() && it->len < temp.len)
        it++;
    if (it == buff.end()) return false;

    int head = it->head;
    int len = it->len;
    buff.erase(it);
    run.insert(Exec(head, temp.len, curT + temp.T));
    if (len > temp.len) {
        buff.insert(Mem(head + temp.len, len - temp.len));
    }
    return true;
}

int main() {
    cin >> N;
    n = 0;
    while (++n) {
        cin >> t[n] >> m[n] >> p[n];
        if (!(t[n] || m[n] || p[n] )) break;
    }
    n--;
    buff.insert(Mem(0, N));

    int T = -1;
    int i = 1;
    int cnt = 0;
    while (i <= n || Q.size() || run.size()) {
        T++;

        //1.释放运行结束的程序
        while (run.size() && run.begin()->endtime == T) {
            Mem temp(run.begin()->head, run.begin()->len);
            mergeInsert(temp);
            run.erase(run.begin());
        }

        //2.处理队列中的程序
        while (Q.size()) {
            if (!work(Q.front(), T)) break;
            Q.pop();
        }

        //3.处理后续程序
        while (i <= n && t[i] == T) {
            if (!work(Prog(m[i], p[i]), T)) {
                Q.push(Prog(m[i], p[i]));
                cnt++;
            }
            i++;
        }
    }
    cout << T << endl;
    cout << cnt << endl;
    return 0;
}