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
const int maxn = 30 + 3;
const int maxm = 100 + 3;

struct edge{
	int v, nxt;
};

class maxMatch{
public:
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
		for(int e = head[u]; e != -1; e = E[e].nxt){
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

	int MaxMatch(){
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

	int cnt;
	void addedge(int u,int v){
		E[cnt].v = v, E[cnt].nxt = head[u], head[u] = cnt++;
		//E[cnt].v = u, E[cnt].nxt = head[v], head[v] = cnt++;
	}

	void gragh(int n){
		memset(head,-1,sizeof(head));
		cnt = Nx = Ny = 0;
		char s[6][6];
		int r[6], c[6];
		memset(r,-1,sizeof(r));
		memset(c,-1,sizeof(c));
		for(int i = 0; i < n; ++i)
			scanf("%s",s[i]);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(s[i][j] == '.'){
					if(r[i] == -1) r[i] = Nx++;
					if(c[j] == -1) c[j] = Ny++;
					addedge(r[i],c[j]);
				}
				else {
					r[i] = c[j] = -1;
				}
			}
		}
	}
}g;

int main(){
	int n;
	while(~scanf("%d",&n) && n){
		g.gragh(n);
		printf("%d\n",g.MaxMatch());
	}
	return 0;
}
