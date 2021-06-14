#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
    double angle;
    double dist;
};

typedef Point Vector;

Point l1, l2;
Point s, t;

void flip(Point& s, Point& l1) {
    s.angle = 2 * l1.angle - s.angle;
    s.x = s.dist * cos(s.angle);
    s.y = s.dist * sin(s.angle);
}

int main() {

    cin >> l1.x >> l1.y;
    cin >> l2.x >> l2.y;
    cin >> s.x >> s.y;
    cin >> t.x >> t.y;

    l1.angle = atan2(l1.y, l1.x);
    l2.angle = atan2(l2.y, l2.x);
    if (l1.angle > l2.angle) swap(l1, l2);

    s.angle = atan2(s.y, s.x);
    t.angle = atan2(t.y, t.x);
    if (s.angle > t.angle) swap(s, t);

    s.dist = sqrt(s.x * s.x + s.y * s.y);
    t.dist = sqrt(t.x * t.x + t.y * t.y);

    //cout << l1.angle << " " << l2.angle << endl;
    //cout << s.angle << " " << t.angle << endl;

    if (s.angle > l1.angle) {
        flip(s, l1);
    }

    if (t.angle < l2.angle) {
        flip(t, l2);
    }
    //cout << s.x << " " << s.y << endl;
    //cout << t.x << " " << t.y << endl;
    double ans = sqrt((s.x - t.x) * (s.x - t.x) + (s.y - t.y) * (s.y - t.y));
    printf("%.3lf\n", ans);

    return 0;
}

int main1() {

    cout << atan2(0, 1) << endl;

    return 0;
}