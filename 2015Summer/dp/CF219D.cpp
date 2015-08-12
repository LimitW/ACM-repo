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
const int maxn = 2e5 + 3;
//const int maxm = maxn * maxn;

vector<pii> G[maxn];
int dp[maxn];

void dfs(int u, int fa = -1){
	for(int i = 0; i < G[u].size(); ++i){
		int v = G[u][i].first, d = G[u][i].second;
		if(v == fa) continue;
		dfs(v,u);
		dp[u] += dp[v] + d;
	}
}

void dfs2(int u,int fa = -1, int e = -1){
	if(fa != -1 && e != -1){
		if(e) dp[u] = dp[fa] - 1;
		else dp[u] = dp[fa] + 1;
	}
	for(int i = 0; i < G[u].size(); ++i){
		int v = G[u][i].first, d = G[u][i].second;
		if(v == fa) continue;
		dfs2(v,u,d);
	}
}

int main(){
	memset(dp, 0, sizeof(dp));
	int n; scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i){
		int u, v; scanf("%d %d", &u, &v);
		G[u].push_back(make_pair(v,0));
		G[v].push_back(make_pair(u,1));
	}
	dfs(1);
	dfs2(1);
	int ans = INF;
	for(int i = 1; i <= n; ++i)
		ans = min(ans, dp[i]);
	vector<int> p;
	p.clear();
	for(int i = 1; i <= n; ++i){
		if(ans == dp[i]) p.push_back(i);
	}
	printf("%d\n", ans);
	for(int i = 0; i < p.size(); ++i)
		printf("%d%c", p[i], i == p.size()-1 ? '\n':' ');
    return 0;
}

