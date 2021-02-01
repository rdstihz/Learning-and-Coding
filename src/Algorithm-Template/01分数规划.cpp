//POJ-2976  Dropping tests 

#include <cstdio>
#include <algorithm>


using namespace std;
const int maxn = 1000 + 10;
const double delta = 1e-5;
int n,k;

int a[maxn],b[maxn];

double value[maxn];

bool check(double x){
	
	for(int i = 1;i<=n;i++){
		value[i] = a[i]-x*b[i];
	}
	sort(value+1,value+1+n);
	double res = 0;
	for(int i = n;i>k;i--) res += value[i];
	return res >= 0;
	
}

int main(){
	
	while(scanf("%d%d",&n,&k) == 2 && n ){
		for(int i = 1;i<=n;i++) scanf("%d",a+i);
		for(int i = 1;i<=n;i++) scanf("%d",b+i);
		
		double l = 0;
		double r = 1;
		double m;
		check(1);
		while(r-l>delta){
			m = (l+r)/2;
			if(check(m)) l = m;
			else r = m-delta;
		}
	
		printf("%.0lf\n",100*l); 
	}
	
	return 0;
} 
