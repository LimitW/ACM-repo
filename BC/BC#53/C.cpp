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
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 1e3 + 3;
const int maxm = 2e5 + 3;
const double eps = 1e-9;

int n;
int d[maxn];
vector<int> G[maxn];
set<pii> e;
bool vis[maxn];

bool dfs(int u, int dep){
	if(dep == n) return true;
	for(int i = 0; i < G[u].size(); ++i){
		int v = G[u][i];
		if(vis[v]) continue;
		vis[v] = 1;
		if(dfs(v, dep + 1)) return true;
		vis[v] = 0;
	}
	return false;
}

int main(){
	while(~scanf("%d", &n)){
		for(int i = 1; i <= n; ++i){
			G[i].clear();
			vis[i] = d[i] = 0;
		}
		e.clear();
		for(int i = 0; i < n; ++i){
			int u, v; scanf("%d%d", &u, &v);
			if(u > v) swap(u, v);
			if(e.count(make_pair(u, v)) || u == v) continue;
			G[u].push_back(v), G[v].push_back(u);
			e.insert(make_pair(u, v));
			++d[u], ++d[v];
		}
		if(n == 1) { puts("YES"); continue; }
		if(e.size() < n - 1) { puts("NO"); continue; }
		int i;
		for(i = 1; i <= n; ++i)
			if(d[i] == 1) break;
		if(i > n) i = 1;
		vis[i] = 1;
		if(dfs(i, 1)) puts("YES");
		else puts("NO");
	}
	return 0;
}

