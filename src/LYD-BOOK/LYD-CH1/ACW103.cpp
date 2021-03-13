#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 10;

int a[maxn],b[maxn],c[maxn];
int temp[3*maxn];
int n,m;
int cnt;
int num[3*maxn];

void discrete(){
	sort(temp+1,temp+1+2*m+n);
	cnt = unique(temp+1,temp+1+2*m+n) - temp - 1;
	
	for(int i = 1;i<=n;i++){
		a[i] = lower_bound(temp+1,temp+1+cnt,a[i]) - temp;
	}
	for(int i = 1;i<=m;i++){
		b[i] = lower_bound(temp+1,temp+1+cnt,b[i]) - temp;
		c[i] = lower_bound(temp+1,temp+1+cnt,c[i]) - temp;
	}
	
}

int main(){
	
	scanf("%d",&n);
	
	for(int i = 1;i<=n;i++){
		scanf("%d",a+i);
		temp[i] = a[i]; 
	}
	
	scanf("%d",&m);
	for(int i = 1;i<=m;i++){
		scanf("%d",b+i);
		temp[n+i] = b[i];
	}
	for(int i = 1;i<=m;i++){
		scanf("%d",c+i);
		temp[n+m+i] = c[i];
	}
	
	
	discrete();
	
	for(int i  = 1;i<=n;i++) num[a[i]]++;
	int ans = 1;
	
	for(int i =2;i<=m;i++){
		if(num[b[i]] > num[b[ans]] || (num[b[i]] == num[b[ans]] && num[c[i]] > num[c[ans]]  ) )
			ans = i;
	}
	printf("%d\n",ans);
	
	return 0;
}
