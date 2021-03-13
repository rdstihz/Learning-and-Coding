#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1000 + 10;
typedef long long LL;
LL l[maxn],r[maxn];
int q[maxn];

bool cmp(int a,int b){
	return l[a]*r[a] < l[b]*r[b];
}

int ans[5000];
int prod[5000];
int temp[5000];

void mul(int *a,int b,int *p){
	memset(p,0,4*5000);
	
	p[0] = a[0];
	for(int i = 1;i<=a[0];i++){
		p[i] += a[i]*b;
		p[i+1] += p[i]/10;
		p[i] %= 10; 
	}
	
	while(p[ p[0] + 1]) {
		p[0]++;
		p[p[0] + 1] += p[p[0]] / 10;
		p[p[0]] %= 10;
	}
	
}

void devide(int* a,int b,int *p){
	memset(p,0,4*5000);
	p[0] = a[0];
	int t = 0;
	
	for(int i = a[0];i>=1;i--){
		t = t*10 + a[i];
		p[i] += t/b;
		t %= b;
	}
	while(!p[p[0]] && p[0]>0) p[0]--;
}


int mai1n(){
	ans[0] = 1; ans[1] = 1;
	
	mul(ans,1234,temp);
	
	for(int i = temp[0];i>=1;i--) printf("%d",temp[i]);
	printf("\n");
	
	mul(temp,1234,ans);
	for(int i = ans[0];i>=1;i--) printf("%d",ans[i]);
	printf("\n");
	
	devide(ans,1234,temp);
	for(int i = temp[0];i>=1;i--) printf("%d",temp[i]);
	printf("\n");
	
}


bool larger(int* a,int* b){
	if(a[0] == b[0]){
		for(int i = a[0];i>=1;i--){
			if(a[i] > b[i]) return true;
			else if(a[i] < b[i]) return false;
		}
		return false;
	}
	
	return a[0] > b[0];
}

int main(){
	int n;
	LL a,b;
	scanf("%d",&n);
	scanf("%lld%lld",&a,&b);
	
	for(int i = 1;i<=n;i++){
		q[i] = i;
		scanf("%d%d",l+i,r+i);
	}
	sort(q+1,q+1+n,cmp);
	
	ans[0] = 1; ans[1] = 0;
	temp[0] = temp[1] = 1;
	mul(temp,a,prod);
	
	for(int e = 1;e<=n;e++){
		int i = q[e];
//		ans = max(ans,prod/r[i]);
//		prod = prod*l[i];
		
		devide(prod,r[i],temp);
		if(larger(temp,ans)) {
			memcpy(ans,temp,sizeof(temp));
		}
		mul(prod,l[i],temp);
		memcpy(prod,temp,sizeof(temp));
	}
	
	for(int i = ans[0];i>=1;i--) printf("%d",ans[i]);
	printf("\n");
	
	return 0;
} 
