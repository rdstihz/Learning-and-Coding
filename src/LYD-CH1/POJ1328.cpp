#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 1010;

struct Island{
	int x,y;
	double l,r;
	bool operator < (const Island& phs) const {
		return l < phs.l;
	}
}a[maxn];


int n,r;


int main(){
	int kase = 0;
	while(scanf("%d%d",&n,&r),n||r){
		bool flag = false;
		for(int i = 1;i<=n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			if(a[i].y > r) flag = true;
			double t = sqrt( (double)r*r - (double)a[i].y * a[i].y );
			a[i].l = a[i].x - t;
			a[i].r = a[i].x + t;
		}
		
		if(flag){
			printf("Case %d: -1\n",++kase);
			continue;
		}
		
		sort(a+1,a+1+n);
		int cnt = 0;
		double pos = a[1].l-1;
		
		for(int i = 1;i<=n;i++){
			if(a[i].l <= pos){
				pos = min(pos,a[i].r);
			}
			else{
				cnt++;
				pos = a[i].r;
			}
		}
		printf("Case %d: %d\n",++kase,cnt);
		
	}
	
	return 0;
}
