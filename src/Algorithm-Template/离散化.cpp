#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000000;

int a[maxn],temp[maxn];
int n,cnt;


void discrete(){
	sort(temp+1,temp+1+n);
	int cnt = unique(temp+1,temp+1+n) - temp - 1;
	
	for(int i = 1;i<=n;i++){
		a[i] = lower_bound(temp+1,temp+1+cnt,a[i]) - temp;
	}
	printf("%d\n",cnt);
}

int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",a+i);
		temp[i] = a[i];
	}
	
	discrete();
	
	for(int i = 1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	
	return 0;
}
