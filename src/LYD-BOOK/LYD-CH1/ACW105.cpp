#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn = 100000+100;

LL row[maxn]; 
LL col[maxn];
LL n,m,t;

int main(){
	scanf("%lld%lld%lld",&n,&m,&t);
	
	LL x,y;
	for(int i = 1;i<=t;i++){
		scanf("%lld%lld",&x,&y);
		row[x]++;
		col[y]++;
	}
	
	if(t % n && t % m ) {
		printf("impossible\n");
	}else{
		if(t%n == 0 && t % m == 0) printf("both ");
		else if(t%n == 0) printf("row ");
		else if(t%m == 0) printf("column ");
		
		LL ans = 0;
		//ÐÐ
		if(t%n == 0){
			for(int i = 1;i<=n;i++) row[i] -= t/n;
			for(int i = 1;i<=n;i++) row[i] += row[i-1];
			sort(row+1,row+1+n);
			LL mid = row[(n+1)/2];
			for(int i = 1;i<=n;i++)
				ans += abs(row[i] - mid);
		} 
		
		//ÁÐ
		if(t%m == 0){
			for(int i = 1;i<=m;i++) col[i] -= t/m;
			for(int i = 1;i<=m;i++) col[i] += col[i-1];
			sort(col+1,col+1+m);
			LL mid = col[(m+1)/2];
			for(int i = 1;i<=m;i++) 
				ans += abs(col[i] - mid);
		} 
		
		printf("%lld\n",ans);
		
	}
	
	
	return 0;
} 
