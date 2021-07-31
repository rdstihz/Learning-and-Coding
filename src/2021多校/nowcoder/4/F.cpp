#include <bits/stdc++.h>
#define down 0.996 //徐徐降温

using namespace std;
const int maxn = 110;
const double pi = acos(-1);
int n;

double x[maxn], y[maxn];

double ansx, ansy, answ; //最终答案

double angle(double a, double b, double c, double d) {
    double t = (a * c + b * d) / (sqrt(a * a + b * b) * sqrt(c * c + d * d));
    return acos(t) / pi * 180;
}



double energy(double x0, double y0) //根据物理学知识,能量总和越小越稳定
{
    if (!inside(x0, y0)) return -1e8;
    double res = 180;
    for (int i = 0; i < n; i++) {
        res = min(res, angle(x[i] - x0, y[i] - y0, x[i + 1] - x0, y[i + 1] - y0));
    }
    return res;
}
void sa() //模拟退火
{
    double t = 3000;  //温度要足够高
    while (t > 1e-15) //略大于0
    {
        double ex = ansx + (rand() * 2 - RAND_MAX) * t; //随机产生新的答案
        double ey = ansy + (rand() * 2 - RAND_MAX) * t;
        double ew = energy(ex, ey);
        double de = -ew + answ;
        if (de < 0) //如果此答案更优，就接受
        {
            ansx = ex;
            ansy = ey;
            answ = ew;
        } else if (exp(-de / t) * RAND_MAX > rand()) //否则根据多项式概率接受
        {
            ansx = ex;
            ansy = ey;
        }
        t *= down;
    }
}
void solve() //多跑几遍退火,增加得到最优解的概率
{
    sa();
    sa();
    sa();
    sa();
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", x + i, y + i);
        ansx += x[i];
        ansy += y[i];
    }
    x[0] = x[n], y[0] = y[n];

    ansx /= n; //以平均数作为初始答案
    ansy /= n;
    answ = energy(ansx, ansy);
    solve();
    printf("%.3lf %.3lf\n", ansx, ansy); //华丽的输出
    printf("%.10f\n", answ);
    return 0;
}