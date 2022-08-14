#include <bits/stdc++.h>
#define app(a, b, c) ans.push_back(Node(a, b, c))

using namespace std;

const int maxn = 4000 + 100;

char s[25][maxn];

struct Node{
	char a;
	int b, c;
	
	Node(char a, int b,int c):a(a), b(b), c(c) {
		
	}
};

int main() {
	int w, n;
	
	scanf("%d%d", &w, &n);
	
	
	int topline = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
		if(topline) continue;
		for(int j = 1; j <= w; j++) {
			if(s[i][j] == '#') {
				topline = i;
				break;
			}
		}
	}
	
	vector<Node> ans;
	//ÆæÊý£¬×ó±ß 
	if((w & 1) && (s[topline][1] == '#' || s[topline][2] == '#' || topline == 0 )) {
		app('L', 0, 1); 
		
		for(int i = 2; i <= w - 3; i += 2) {
			app('Z', 0, i);
		}
		for(int i = 1; i <= w - 4; i += 2) {
			app('Z', 0, i);
		}
		app('T', 1, w - 1);
		app('T', 0, w - 2);
	}
	//ÆæÊý£¬ ÓÒ±ß 
	else if( (w & 1) && (s[topline][w-1] == '#' || s[topline][w] == '#' ) ){
		app('J', 0, w - 1);
		
		for(int i = w - 3; i >= 2; i -= 2) {
			app('S', 0, i);
		}
		for(int i = w - 2; i >= 3; i -= 2) {
			app('S', 0, i);
		}
		app('T', 3, 1);
		app('T', 0, 1);
		
	}
	//ÆæÊý£¬ÖÐ¼ä
	else if(w&1){
		int pos = 0;
		for(int i = 1; i <= w; i++) {
			if(s[topline][i] == '#') {
				pos = i;
				break;
			}
		}
		if(pos % 2 == 1) pos--;
		
		app('T', 2, pos);
		for(int i = pos - 2; i >= 2; i -= 2) {
			app('S', 0, i);
		}
		for(int i = pos + 2; i <= w - 3; i += 2) {
			app('Z', 0, i);
		}
		
		app('T', 3, 1);
		app('T', 1, w - 1);
		for(int i = 1; i <= w - 4; i += 2) {
			app('Z', 0, i);
		}
		app('T', 0, w - 2);	
	}
	//Å¼Êý£¬×ó±ß
	else if( s[topline][1] == '#' || s[topline][2] == '#'||topline == 0  ) {
		app('L', 0, 1);
		for(int i = 2; i <= w - 2; i += 2){
			app('Z', 0, i);
		}
		for(int i = 1; i <= w - 5; i += 2) {
			app('Z', 0, i);
		}
		app('T', 1, w - 1);
		app('T', 0, w - 3);
	}
	//Å¼Êý£¬ÓÒ±ß
	else if(s[topline][w-1] == '#' || s[topline][w] == '#') {
		app('J', 0, w - 1);
		for(int i = w - 3; i >= 1; i -= 2) {
			app('S', 0, i);
		}
		for(int i = w - 2; i >= 4; i -= 2) {
			app('S', 0, i);
		}
		app('T', 3, 1);
		app('T', 0, 2);
	}
	//Å¼Êý£¬ÖÐ¼ä
	else {
		int pos = 0;
		for(int i = 1; i <= w; i++) {
			if(s[topline][i] == '#') {
				pos = i;
				break;
			}
		}
		if(pos % 2 == 0) pos--;
		app('T', 2, pos); //ÉÙÁËÕâÐÐ 
		for(int i = pos - 2; i >= 1; i -= 2) {
			app('S', 0, i);
		}
		for(int i = pos + 2; i <= w - 3; i += 2) {
			app('Z', 0, i);
		}
		app('T', 1, w - 1);
		app('T', 3, 1);
		for(int i = 2; i <= w - 4; i += 2) {
			app('Z', 0, i);
		}
		app('T', 0, w - 2);
		
	}
	printf("%d\n", (int)ans.size());
	for(auto& y : ans) {
		printf("%c %d %d\n", y.a, y.b, y.c);
	}
	
	return 0;
} 

/*
5 2
#....
.#..#
5
L 0 1
Z 0 2
Z 0 1
T 1 4
T 0 3


5 4
#....
###..
####.
#..#.
5
L 0 1
Z 0 2
Z 0 1
T 1 4
T 0 3
*/
