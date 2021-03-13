#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1010;

struct Island{
	int x,y;
	double l,r;
	bool operator < (const Island& phs) const{
		return l < phs.l; 
	}
}a[maxn];

int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	bool flag = false;
	for(int i = 1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		
		if(a[i].y > r) flag = true;
		double t = sqrt(r*r - a[i].y * a[i].y);
		a[i].l = a[i].x - t;
		a[i].r = a[i].x + t;
		
	}
	
	if(flag) {
		printf("-1\n");
		return 0;
	}
	
	sort(a+1,a+1+n);
	
	double pos = a[1].l - 1;
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(a[i].l > pos) { //ÐÂ½¨ 
			cnt++;
			pos = a[i].r;
		}
		else{ //ÒÆ¶¯ 
			pos = min(pos,a[i].r);
		}
		
		
	}
	
	printf("%d\n",cnt);
	return 0;
}
