#include <cstdio>
#include <cstring>
#include <cctype>

typedef long long LL;

const int maxn = 1000;

char s[maxn];
char s2[maxn],p;
int st[maxn],top;

void print(int i) {
	for(int j = 1; j <= top; j++) 
		printf("%d ",st[j]);
	for(int j = i+1; j <= p; j++)
		printf("%c ",s2[j]);
	printf("\n");
}

int main(){
	
	scanf("%s",s+1);
	p = top = 0;
	
	int n = strlen(s+1);
	
	for(int i = 1; i <= n; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			s2[++p] = s[i];
		}
		else if(s[i] == '(') {
			st[++top] = s[i];
		}
		else if(s[i] == ')') {
			while(top && st[top] != '(') {
				s2[++p] = st[top--];
			}
			top--;
		}
		else if(s[i] == '^' ){
			while(top && st[top] != '(' ){
				s2[++p] = st[top--];
			}
			st[++top] = s[i];
		}
		else if(s[i] == '+' || s[i] == '-' ){
			while(top && st[top] != '(' && st[top] != '^' ){
				s2[++p] = st[top--];
			}
			st[++top] = s[i];
		}
		else if(s[i] == '*' || s[i] == '/') {
			while(top && st[top] != '(' && st[top] != '^' && st[top] != '+' && st[top] != '-' ){
				s2[++p] = st[top--];
			}
			st[++top] = s[i];
		}
		
	}
	
	while(top) {
		s2[++p] = st[top--];
	}
	
	print(0);
	
	for(int i = 1; i <= p; i++) {
		if(s2[i] >= '0' && s2[i] <= '9' ) {
			st[++top] = s2[i] - '0';
		}
		else if(s2[i] == '+' ) {
			int b = st[top--];
			int a = st[top--];
			st[++top] = a + b;
			print(i);
		}
		else if(s2[i] == '-' ) {
			int b = st[top--];
			int a = st[top--];
			st[++top] = a - b;
			print(i);
		}
		else if(s2[i] == '*' ) {
			int b = st[top--];
			int a = st[top--];
			st[++top] = a * b;
			print(i);
		}
		else if(s2[i] == '/' ) {
			int b = st[top--];
			int a = st[top--];
			st[++top] = a / b;
			print(i);
		}
		else if(s2[i] == '^' ) {
			int b = st[top--];
			int a = st[top--];
			st[++top] = a ^ b;
			print(i);
		}
		
	}
	return 0;
}
