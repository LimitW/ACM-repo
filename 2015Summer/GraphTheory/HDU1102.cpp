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
const int maxn = 110;
const int maxm = 6000;

struct edge {
	int u, v, w;
	bool operator < (edge b) const {
		return w < b.w;
	}
}edge[maxm];

int e;

void addedge(int uu, int vv, int ww){
	edge[e].u = uu, edge[e].v = vv, edge[e++].w = ww;
}

int p[maxn];

int Find(int u){
	return p[u] == u ? u : p[u] = Find(p[u]);
}

void Union(int x, int y){
	int u = Find(x), v = Find(y);
	if (u != v) p[v] = u;
}


int Kruskal(){
	int ans = 0;
	for (int i = 0; i < e; ++i){
		if (Find(edge[i].u) != Find(edge[i].v)){
			ans += edge[i].w;
			Union(edge[i].u, edge[i].v);
		}
	}
	return ans;
}

int main(){
	int n;
	while (~scanf("%d", &n)){
		e = 0;
		for (int i = 0; i < n; ++i) p[i] = i;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				int ww; scanf("%d", &ww);
				if (i < j) addedge(i, j, ww);
			}
		}
		sort(edge, edge + e);
		int m; scanf("%d", &m);
		for (int i = 0; i < m; ++i){
			int uu, vv; scanf("%d%d", &uu, &vv);
			--uu, --vv;
			if(Find(uu) != Find(vv)) Union(uu, vv);
		}
		printf("%d\n", Kruskal());
	}
	return 0;
}
