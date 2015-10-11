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
const double pi = acos(-1.0);
const long double eps = 1e-9;
const int maxn = 1e6 + 3;

int solve(char *s){
	int n = strlen(s);
	for(int i = 0; i < n; ++i){
		if(s[i] != 'f' && s[i] != 'c') return INF;
	}
	int ans = 0, sc = -1;
	for(int i = n - 1; i >= 0; --i){
		if(s[i] == 'c'){
			sc = i;
			break;
		}
	}
	if(sc == -1) return (n + 1) / 2;
	int pf = 0;
	while(s[pf] == 'f') ++pf;
	if(n - 1 - sc + pf < 2) return INF;
	if(pf == sc) return 1;
	++ans;
	for(int i = pf; i < sc; ++i){
		if(s[i] == 'c'){
			int len = 0;
			for(int j = i + 1; j < sc; ++j){
				if(s[j] == 'c'){
					if(len < 2) return INF;
					else { i = j - 1; break; }
				}
				else ++len;
			}
			if(len < 2) return INF;
			else ++ans;
		}
	}
	return ans;
}

int main(){
	char ss[maxn], tt[maxn];
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%s", ss);
		int n = strlen(ss);
		for(int i = 0; i < n; ++i)
			tt[i] = ss[n-1-i];
		tt[n] = 0;
		int p = min(solve(ss), solve(tt));
		if(p == INF) p = -1;
		printf("Case #%d: %d\n", kase, p);
	}
	return 0;
}

