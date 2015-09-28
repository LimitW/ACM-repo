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
const double pi = acos(-1.0);
const long double eps = 1e-9;

const int maxn = 1e3 + 3;
const int maxm = 1e5 + 3;

struct edge{
	int u, v, w, nxt;
}E[maxm], Erev[maxm];

int head[maxn], revhead[maxn], e;

void addedge(int u, int v, int w){
	E[e].u = u, E[e].v = v, E[e].w = w;
	E[e].nxt = head[u], head[u] = e;
	Erev[e].u = v, Erev[e].v = u, Erev[e].w = w;
	Erev[e].nxt = revhead[v], revhead[v] = e++;
}

int n, m, s, t;
int vis[maxn], dist[maxn];
priority_queue<pii, vector<pii>, greater<pii> > pq;

void Dijkstra(){
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; ++i){
		dist[i] = i == t ? 0 : INF;
	}
	while(!pq.empty()) pq.pop();
	pq.push(make_pair(0, t));
	while(!pq.empty()){
		pii tp = pq.top();
		pq.pop();
		int u = tp.second;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = revhead[u]; ~i; i = Erev[i].nxt){
			int v = Erev[i].v, w = Erev[i].w;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

struct node{
	int u, h, g;
	node(int u = -1, int h = 0, int g = 0):u(u), h(h), g(g){};
	bool operator < (node b) const{
		return g + h > b.g + b.h;
	}
};

int cnt[maxn], k;
priority_queue<node> Q;

int astar(){
	memset(cnt, 0, sizeof(cnt));
	while(!Q.empty()) Q.pop();
	Q.push(node(s, dist[s], 0));
	while(!Q.empty()){
		node tp = Q.top();
		Q.pop();
		if(++cnt[tp.u] > k) continue;
		if(tp.u == t && cnt[t] == k) return tp.g;
		for(int i = head[tp.u]; ~i; i = E[i].nxt){
			int v = E[i].v, w = E[i].w;
			Q.push(node(v, dist[v], w + tp.g));
		}
	}
	return -1;
}

int main(){
	while(~scanf("%d%d", &n, &m)){
		e = 0;
		memset(head, -1, sizeof(head));
		memset(revhead, -1, sizeof(revhead));
		for(int i = 0; i < m; ++i){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			addedge(u, v, w);
		}
		scanf("%d%d%d", &s, &t, &k);
		Dijkstra();
		if(s == t) ++k;
		if(dist[s] == INF) puts("-1");
		else printf("%d\n", astar());
	}
    return 0;
}

