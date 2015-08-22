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
const int maxn = 1 << 16;
//const int maxm = maxn * maxn;

int n, m;
int mp[16][16];
int dp[16][maxn];

int dfs(int e, int st){
	if(dp[e][st] != -1)
		return dp[e][st];
	dp[e][st] = INF;
	for(int i = 0; i < n; ++i){
		if(mp[i][e] == INF || i == e) continue;
		if(st & (1 << i))
			dp[e][st] = min(dp[e][st], dfs(i,st-(1<<e)) + mp[i][e]);
	}
	return dp[e][st];
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		memset(mp, INF, sizeof(mp));
		memset(dp, -1, sizeof(dp));
		scanf("%d%d", &n, &m);
		for(int i = 0; i < m; ++i){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			--u, --v;
			mp[u][v] = min(mp[u][v],w);
			mp[v][u] = mp[u][v];
		}
		if(n == 1){
			puts("0");
			continue;
		}
		for(int i = 0; i < n; ++i)
			mp[i][i] = 0;
		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					mp[i][j] = min(mp[i][j],mp[i][k] + mp[k][j]);
		for(int i = 1; i < n; ++i){
			dp[i][1<<i] = mp[0][i];
		}
		printf("%d\n",dfs(0,(1<<n)-1));
	}
    return 0;
}

