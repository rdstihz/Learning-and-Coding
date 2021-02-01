//ACW107 归并排序求逆序对 

#include <cstdio>

const int maxn = 500000 + 100;

int a[maxn];
int b[maxn];

long long ans;

void mergesort(int l,int r){
	if(l == r) return;
	
	int m = l+r>>1;
	mergesort(l,m);
	mergesort(m+1,r);
	
	int i = l,j = m+1;
	int p = l;
	while(i<=m && j<=r){
		if(a[i] < a[j]) {
			b[p++] = a[i++];
		}else {
			ans = ans + (m-i+1);
			b[p++] = a[j++];
		}
	}
	while(i<=m) b[p++] = a[i++];
	while(j<=r) b[p++] = a[j++];
	for(int i = l;i<=r;i++) a[i] = b[i];
	
}

int main(){
	int n;
	while(~scanf("%d",&n) && n ){
		for(int i = 1;i<=n;i++) 
			scanf("%d",a+i);
		ans = 0;
		
		mergesort(1,n);
		printf("%lld\n",ans); 
		
		
	}
	
	
	return 0;
}
