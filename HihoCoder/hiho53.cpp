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
const int maxn = 2e4 + 3;
const int maxm = 2e5 + 3;
const double eps = 1e-9;

struct Edge {
	int u, v;
	Edge(int uu = -1, int vv = -1): u(uu), v(vv){}
}E[maxm];


int n, m, e, ck;
int head[maxn], nxt[maxm];

int pre[maxn], low[maxn];
bool iscut[maxn], iscutm[maxm];

void addedge(int uu, int vv){
	E[e] = Edge(uu, vv);
	nxt[e] = head[uu], head[uu] = e++;
}

int dfs(int u, int fa){
	int lowu = pre[u] = ++ck;
	int child = 0;
	for(int i = head[u]; i != -1; i = nxt[i]){
		int v = E[i].v;
		if(!pre[v]){
			++child;
			int lowv = dfs(v, u);
			lowu = min(lowv, lowu);
			if(lowv >= pre[u]) iscut[u] = 1;
			if(lowv > pre[u]){
				iscutm[i] = iscutm[i^1] = 1;
			}
		}
		else if(pre[v] < pre[u] && v != fa){
			lowu = min(lowu, pre[v]);
		}
	}
	if(fa == -1 && child == 1) iscut[u] = 0;
	low[u] = lowu;
	return lowu;
}

int p[maxn];

int getfa(int x){
	return p[x] == x ? x : p[x] = getfa(p[x]);
}

void Union(int x, int y){
	int u = getfa(x), v = getfa(y);
	if(u < v) swap(u, v);
	if(u != v) p[u] = v;
}

int main(){
	while(~scanf("%d%d", &n, &m)){
		memset(head, -1, sizeof(head));
		memset(pre, 0, sizeof(pre));
		memset(low, 0, sizeof(low));
		memset(iscut, 0, sizeof(iscut));
		memset(iscutm, 0, sizeof(iscutm));
		e = ck = 0;
		for(int i = 0; i < m; ++i){
			int uu, vv;
			scanf("%d%d", &uu, &vv);
			addedge(uu, vv);
			addedge(vv, uu);
		}
		for(int i = 1; i <= n; ++i)
			if(!pre[i]) dfs(i, -1);
		for(int i = 1; i <= n; ++i)
			p[i] = i;
		for(int i = 0; i < e; ++i){
			if(iscutm[i]) continue;
			Union(E[i].u, E[i].v);
		}
		int cnt = 0;
		for(int i = 1; i <= n; ++i)
			if(getfa(i) == i) ++cnt;
		printf("%d\n", cnt);
		for(int i = 1; i <= n; ++i){
			printf("%d%c", getfa(i), i == n ? '\n' : ' ');
		}
	}
	return 0;
}

