#include <cstdio>

const int maxn = 300000;
typedef long long LL;
int a[maxn];
int b[maxn];

void mergesort(int l,int r,LL *ans){
	if(l >= r) return ;
	int m = l+r>>1;
	mergesort(l,m,ans);
	mergesort(m+1,r,ans);
	
	int i = l,j = m+1;
	int p = l;
	while(i<=m && j<=r){
		if(a[i] < a[j]){
			b[p++] = a[i++];
		}
		else{
			*ans = *ans + (m-i+1);
			b[p++] = a[j++];
		}
	}
	while(i<=m) b[p++] = a[i++];
	while(j<=r) b[p++] = a[j++];
	
	for(int i = l;i<=r;i++) a[i] = b[i];
	
}

int main(){
	int n;
	while(scanf("%d",&n) == 1 && n ){
		int t = 0;
		int x;
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++){
				scanf("%d",&x);
				if(x) a[++t] = x;
			}
		LL cnt1 = 0;
		LL cnt2 = 0;
		mergesort(1,t,&cnt1);
		
		t = 0;
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++){
				scanf("%d",&x);
				if(x) a[++t] = x;
			}
		mergesort(1,t,&cnt2);
		
		if(cnt1%2 == 1 && cnt2 % 2 == 1 ) printf("TAK\n");
		else if(cnt1%2 == 0 && cnt2%2 == 0) printf("TAK\n");
		else printf("NIE\n");		
	}
	
	
	
	return 0;
}
