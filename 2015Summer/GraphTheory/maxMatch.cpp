//hdu 2444
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
const int maxn = 200 + 3;
const int maxm = maxn * maxn;

struct edge{
	int v, nxt;
};

class Hungary{
public:
	int n, m;
	edge E[maxm];
	int head[maxn], match[maxn];
	bool vis[maxn];
	int dfs(int u){
		for(int e = head[u]; ~e; e = E[e].nxt){
			int v = E[e].v;
			if(vis[v]) continue;
			vis[v] = 1;
			if(match[v] == -1 || dfs(match[v])){
				match[v] = u;
				return 1;
			}
		}
		return 0;
	}

	int maxmatch(){
		int res = 0;
		memset(match, -1, sizeof(match));
		for(int i = 0; i < n; ++i){
			memset(vis, 0, sizeof(vis));
			if(dfs(i)) ++res;
		}
		return res;
	}

	int ecnt;

	void addedge(int u,int v){
		E[ecnt].v = v, E[ecnt].nxt = head[u], head[u] = ecnt++;
	}

};

class HK{
public:
	int n, m;
	edge E[maxm];
	int head[maxn];
	int Mx[maxn], My[maxn], Nx, Ny;
	int dx[maxn], dy[maxn], dis;
	bool vis[maxn];

	bool bfs(){
		queue<int> q;
		while(!q.empty()) q.pop();
		dis = INF;
		memset(dx, -1, sizeof(dx));
		memset(dy, -1, sizeof(dy));
		for(int i = 0; i < Nx; ++i){
			if(Mx[i] == -1){
				q.push(i), dx[i] = 0;
			}
		}
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(dx[u] > dis) break;
			for(int e = head[u]; e != -1; e = E[e].nxt){
				int v = E[e].v;
				if(dy[v] == -1){
					dy[v] = dx[u] + 1;
					if(My[v] == -1) dis = dy[v];
					else{
						dx[My[v]] = dy[v] + 1;
						q.push(My[v]);
					}
				}
			}
		}
		return dis != INF;
	}

	bool dfs(int u){
		for(int e = head[u]; ~e; e = E[e].nxt){
			int v = E[e].v;
			if(!vis[v] && dy[v] == dx[u] + 1){
				vis[v] = 1;
				if(My[v] != -1 && dy[v] == dis) continue;
				if(My[v] == -1 || dfs(My[v])){
					My[v] = u, Mx[u] = v;
					return 1;
				}
			}
		}
		return 0;
	}

	int maxmatch(){
		int res = 0;
		memset(Mx, -1, sizeof(Mx));
		memset(My, -1, sizeof(My));
		while(bfs()){
			memset(vis, 0, sizeof(vis));
			for(int i = 0; i < Nx; ++i)
				if(Mx[i] == -1 && dfs(i)) ++res;
		}
		return res;
	}

	int ecnt;
	void addedge(int u,int v){
		E[ecnt].v = v, E[ecnt].nxt = head[u], head[u] = ecnt++;
	}

	int color[maxn];

	bool isbipartite(int u){
		for(int e = head[u]; ~e; e = E[e].nxt){
			int v = E[e].v;
			if(color[v] == color[u]) return 0;
			if(color[v] == -1){
				color[v] = color[u] ^ 1;
				if(!isbipartite(v)) return 0;
			}
		}
		return 1;
	}

	void gragh(){
		memset(head, -1, sizeof(head));
		ecnt = 0;
		Nx = Ny = n;
		for(int i = 0; i < m; ++i){
			int u, v; scanf("%d%d", &u, &v);
			--u, --v;
			addedge(u, v);
		}
		memset(color, -1, sizeof(color));
		color[0] = 0;
	}
};



int main(){
	int n,m;
	while(~scanf("%d%d", &n, &m)){
		HK g;
		g.n = n, g.m = m;
		g.gragh();
		if(!g.isbipartite(0)) puts("No");
		else printf("%d\n",g.maxmatch());
	}
	return 0;
}


