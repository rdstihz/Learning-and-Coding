#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 100;
const double delta = 0.0001;

int h[maxn];
double hh[maxn];
double sum[maxn];
int n,f;

bool check(double x){
	for(int i = 1;i<=n;i++) hh[i] = h[i] - x;
	for(int i = 1;i<=n;i++) sum[i] = hh[i] + sum[i-1];
	
	double min_sum = 1e10;
	double ans = -1e10;
	for(int i = f;i<=n;i++){
		min_sum = min(min_sum, sum[i-f] );
		ans = max(ans, sum[i] - min_sum );
	}
	return ans >= 0;
}

int main(){
	scanf("%d%d",&n,&f);
	
	for(int i = 1;i<=n;i++) scanf("%d",h+i);
	
	double l = 1,r = 2000;
	double m;
	while(l+delta < r){
		m = (l+r) / 2;
		if(check(m)) l = m;
		else r = m;
	} 
	int ans = r*1000;
	printf("%d\n",ans);
	
	
	return 0;
} 
