#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2500 + 100;
int l[maxn],r[maxn];
int q[maxn];

int v[maxn];

bool cmp(int a,int b){
	if(r[a] == r[b]) return l[a] < l[b];
	return r[a] < r[b];
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++) scanf("%d%d",l+i,r+i),q[i] = i;
	int a,b;
	for(int i = 1;i<=m;i++){
		scanf("%d%d",&a,&b);
		v[a] += b;
	}
	sort(q+1,q+1+n,cmp);
	
	int light = 0;
	
	int ans = 0;
	
	for(int t=  1;t<=n;t++){
		int i = q[t];
		for(light = l[i]; !v[light] && light <=r[i] ;light++);
		if(light <= r[i]){
			ans++;
			v[light]--;
		}
		
	}
	printf("%d\n",ans);
	
	return 0;
} 

