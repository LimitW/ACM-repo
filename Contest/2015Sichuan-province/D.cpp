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

bitset<500> bits[30];
int n, m, ans;

void dfs(int d, bitset<500> cur){
	int cnt = cur.count();
	if(cnt >= ans) return;
	if(d == min(n, 30)) ans = min(ans, cnt);
	if(cur[d]) dfs(d + 1, cur);
	else{
		cur[d] = 1;
		dfs(d + 1, cur);
		cur[d] = 0;
		dfs(d + 1, cur | bits[d]);
	}
}

int main(){
	while(~scanf("%d%d", &n, &m)){
		for(int i = 0; i < 30; ++i) bits[i].reset();
		for(int i = 0; i < m; ++i){
			int u, v; scanf("%d%d", &u, &v);
			--u, --v;
			if(u > v) swap(u, v);
			bits[u][v] = 1;
			if(v < 30) bits[v][u] = 1;
		}
		ans = min(n, 30);
		bitset<500> bs; bs.reset();
		dfs(0, bs);
		printf("%d\n", ans);
	}
	return 0;
}


