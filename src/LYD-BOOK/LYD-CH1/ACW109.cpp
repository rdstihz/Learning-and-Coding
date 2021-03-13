#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn = 500000 + 10;

int n,m,k;
LL t;
int l,r,p,q;

int a[maxn],b[maxn],c[maxn];


template<typename T>
void read(T &x){
	x = 0;
	char c;
	for(c = getchar();c<'0'||c>'9';c = getchar());
	for(;c>='0'&&c<='9';x = x*10+c-'0',c = getchar());
	
}


bool cmp(int x,int y){
	return a[x] < a[y];
}

LL calc(int ed){
	LL sum = 0;
	
	for(int i = 1,l=1,r=p;i<=m && sum <=t && l<r ;i++,l++,r--){
		while(l<=p && b[l] >= ed) l++;
		while(r && b[r] >= ed ) r--;
		if(l<r) sum += (LL)(a[b[r]]-a[b[l]]) * (a[b[r]] - a[b[l]] ); 
		
	}
	return sum;
	
}

int nxt(int st){
	p = q = 1;
	b[1] = st;
	l = 1; r = 2;
	
	for(;st+l<=n;l = r,r = l<<1){
		for(int i = st+l;i<min(st+r,n+1);i++) b[++q] = i;
		sort(b+1+p,b+1+q,cmp);
		
		int i = 1,j = p+1;
		int pos = 1;
		while(i<=p && j<=q){
			if(a[b[i]] < a[b[j]] ) c[pos++] = b[i++];
			else c[pos++] = b[j++];
		} 
		while(i<=p) c[pos++] = b[i++];
		while(j<=q) c[pos++] = b[j++];
		
		for(int i = 1;i<=q;i++) b[i] = c[i];
		p = q;
		if(calc(st+p) > t ) break;
	}
	if(st+l > n) return n+1;
	
	r = min(p,r);
	int mid;
	while(l<r){
		mid = l+r>>1;
		if(calc(st+mid) > t ) r = mid;
		else l = mid+1; 
	}
	return st+l-1;
	
}

int main(){
	read(k);
	while(k--){
		read(n);
		read(m);
		read(t);
		
		for(int i = 1;i<=n;i++) read(a[i]);
		
		int ans = 0;
		
		for(int l = 1;l<=n;l = nxt(l)) ans++;
		printf("%d\n",ans);
		
		
	}
	
	return 0;
}
