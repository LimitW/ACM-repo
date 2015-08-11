#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int maxn = 1e5 + 3;
//const int maxm = maxn * maxn;

int sz[maxn];
vector<int> G[maxn];
LL fac[maxn];

int dfs(int u, int fa = -1){
	sz[u] += G[u].size();
	for(int i = 0; i < G[u].size(); ++i){
		int v = G[u][i];
		if(v == fa) continue;
		sz[u] += dfs(v,u);
	}
	return sz[u];
}

LL res;

bool solve(int u, int fa = -1){
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < G[u].size(); ++i){
		int v = G[u][i];
		if(v == fa) continue;
		if(!solve(v,u)) return 0;
		if(sz[v] >= 2) ++cnt2;
		else ++cnt1;
	}
	if(cnt2 > 2) return 0;
	else {
		res *= fac[cnt1], res %= mod;
		if(cnt2 != 0) res *= 2, res %= mod;
	}
	return 1;
}

int main(){
	fac[0] = 1;
	for(int i = 1; i <= maxn; ++i){
		fac[i] = fac[i-1] * i % mod;
	}
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		int n; scanf("%d", &n);
		memset(sz,0,sizeof(sz));
		for(int i = 1; i <= n; ++i) G[i].clear();
		for(int i = 0; i < n - 1; ++i){
			int u, v; scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
		res = 1;
		if(!solve(1)) res = 0;
		else res *= 2;
		if(n == 1) res /= 2;
		printf("Case #%d: %d\n",kase,(int)(res%mod));
	}
    return 0;
}

