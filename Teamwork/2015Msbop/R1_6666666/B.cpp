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
const long long INFL = 1LL << 62;
const int maxn = 1e6+3;

int p[maxn];
pii w[maxn];
bool vis[maxn];

int Find(int x){
	return p[x] == x ? x : p[x] = Find(p[x]);
}

void Union(int x,int y){
	int u = Find(x);
	int v = Find(y);
	if(u == v) return;
	if(w[u] < w[v]) p[v] = u;
	else p[u] = v;
}

int main(){
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T ; ++kase){
		int n , m , k , ret = 0; scanf("%d%d%d",&n,&m,&k);
		memset(vis,0,sizeof(vis));
		for(int i = 1; i <= n; ++i){
			p[i] = i; scanf("%d",&w[i].first);
			w[i].second = i;
		}
		for(int i = 0; i < m; ++i){
			int u,v; scanf("%d%d",&u,&v);
			Union(u,v);
		}
		long long ans = 0;
		for(int i = 1; i <= n; ++i){
			int a = Find(i);
			if(!vis[a]){
				++ret;
				vis[a] = true;
				ans += (long long)w[a].first;
			}
		}
		k -= (m - n + ret);
		if(k <= 0){
			printf("Case #%d: %lld\n",kase,ans);
			continue;
		}
		sort(w+1,w+n+1);
		for(int i = 1; i <= n && k > 0; ++i){
			if(!vis[w[i].second]){
				ans += (long long)w[i].first;
				--k;
			}
		}
		printf("Case #%d: %lld\n",kase,ans);
	}
    return 0;
}

