#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const int maxn = 5e2 + 4;

char s[maxn], t[maxn], ans[maxn];
int nxt[maxn], pre[maxn];

void getnext(char* s){
	nxt[0] = 0, nxt[1] = 0;
	int p = 1, q = 0;
	int n = strlen(s);
	while(p < n){
		while(q > 0 && s[q] != s[p]) q = nxt[q];
		if(s[p] == s[q]) ++q;
		nxt[++p] = q;
	}
}

void kmp(char *s1, char* s2){
	int n1 = strlen(s1), n2 = strlen(s2);
	int p = 0, q = 0, tp = 0;
	while(p < n2){
		ans[tp++] = s2[p];
		while(q > 0 && s1[q] != s2[p]) q = nxt[q];
		if(s1[q] == s2[p]) ++q;
		if(q == n1){
			tp -= n1;
			if(!tp) q = 0;
			else q = pre[tp-1];
		}
		else pre[tp-1] = q;
		ans[tp] = 0, ++p;
	}
}

int main(){
	while(~scanf("%s%s", s, t)){
		getnext(s);
		kmp(s, t);
		puts(ans);
	}
	return 0;
}


