#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 3;

int n, m;

struct Edge{
	int v, nxt;
}E[maxn<<1];

int head[maxn], e;

void AddEdge(int u, int v){
	E[e].v = v, E[e].nxt = head[u], head[u] = e++;
	E[e].v = u, E[e].nxt = head[v], head[v] = e++;
}

int vis[maxn<<1], ans[maxn];
int in[maxn], out[maxn];

void dfs(int u){
	for(int i = head[u]; ~i; i = E[i].nxt){
		if(vis[i]){
			head[u] = E[i].nxt;
			continue;
		}
		if(u != E[i].v && in[E[i].v] > out[E[i].v]) continue;
		head[u] = E[i].nxt;
		++out[u], ++in[E[i].v];
		vis[i] = vis[i^1] = 1;
		ans[i>>1] = !(i & 1);
		dfs(E[i].v);
		return;
	}
}


void dfs2(int u){
	for(int i = head[u]; ~i; i = E[i].nxt){
		if(vis[i]){
			head[u] = E[i].nxt;
			continue;
		}
		if(u != E[i].v && out[E[i].v] > in[E[i].v]) continue;
		head[u] = E[i].nxt;
		++in[u], ++out[E[i].v];
		vis[i] = vis[i^1] = 1;
		ans[i>>1] = (i & 1);
		dfs2(E[i].v);
		return;
	}
}

int num[maxn];

int main(){
	int T; scanf("%d", &T);
	while(T--){
		e = 0;
		memset(head, -1, sizeof(head));
		memset(num, 0, sizeof(num));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		for(int i = 0; i < m; ++i){
			int u, v; scanf("%d%d", &u, &v);
			AddEdge(--u, --v);
			num[u]++, num[v]++;
		}
		for(int i = 0; i < n; ++i){
			while(in[i] + out[i] < num[i])
				if(in[i] >= out[i]) dfs(i);
				else dfs2(i);
		}
		for(int i = 0; i < m; ++i){
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}

