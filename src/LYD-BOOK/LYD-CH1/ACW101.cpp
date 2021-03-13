#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int,int> P;

const int maxn = 100000 + 100;
int b[maxn];
int a[maxn];
map<P,int> Map;


int main(){
	
	int n,p,h,m;
	scanf("%d%d%d%d",&n,&p,&h,&m);
	
	int x,y;
	for(int i = 1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x > y) swap(x,y);
		if(Map.count(P(x,y))) continue;
		Map[P(x,y)] = 1;
		b[x+1]--;
		b[y]++;
		
	}
	
	for(int i = 1;i<=n;i++) a[i] = a[i-1] + b[i];
	for(int i = 1;i<=n;i++) printf("%d\n",a[i] + h);
	
	return 0;
}
