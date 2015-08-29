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

vector<int> G[maxn];
int d[maxn], p[maxn];

void dfs(int u, int dep, int fa = -1){
	d[u] = dep;
	for(int i = 0; i < G[u].size(); ++i){
		int v = G[u][i];
		if(v == fa) continue;
		p[v] = u;
		dfs(v, dep + 1, u);
	}
}

int main(){
	int n;
	while(~scanf("%d", &n)){
		for(int i = 1; i <= n; ++i){
			G[i].clear();
			d[i] = 0;
		}
		for(int i = 0; i < n - 1; ++i){
			int u, v; scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,0);
		bool flag = 0;
		for(int i = 2; !flag && i <= n; ++i)
			for(int j = i + 1; !flag && j <= n; ++j){
				if(p[i] == j || p[j] == i || p[i] == p[j]) continue;
				if(abs(d[j] - d[i]) <= 1) flag = 1;
			}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}

