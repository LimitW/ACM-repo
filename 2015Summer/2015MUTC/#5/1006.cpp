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
const int maxm = 3e5 + 3;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};


struct edge{
	int u,v,id;
	bool operator < (edge p) const {
		return u < p.u || (u == p.u && v < p.v);
	}
	bool operator == (edge p) const{
		return (u == p.u && v == p.v) || (u == p.v && v == p.u);
	}
}E[maxm];


int e;
bool ans[maxm], vis[maxm], tag[maxn];
int n,m;

int head[maxn];
pii nxt[maxm];

vector<int> cp;

void init(){
	e = 0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(tag,0,sizeof(tag));
	memset(ans,0,sizeof(ans));
	cp.clear();
}

void multiedge(){
	sort(E,E+e);
	for(int i = 1; i < e; ++i){
		if(E[i] == E[i-1]){
			int cnt = 2;
			vis[E[i].id] = 1;
			for(int j = i + 1; j < e; ++j){
				if(E[j] == E[j-1]) {
					++cnt;
					ans[E[j].id] = ans[E[j-1].id] ^ 1;
					vis[E[j].id] = 1;
				}
				else { i = j - 1; break; }
			}
			if(!(cnt & 1)){
				vis[E[i-1].id] = 1;
				ans[E[i-1].id] = ans[E[i].id] ^ 1;
			}
		}
	}
}
/*
void cycle(int u,int pre = -1){
	tag[u] = 1;
	bool cannxt = 0;
	for(int i = 0; i < G[u].size(); ++i){
		pii nxt = G[u][i];
		int eid = nxt.second, v = nxt.first;
		if(vis[eid] || (pre != -1 && E[pre].u == v)) continue;
		cannxt = 1;
		cp.push_back(eid);
		if(tag[v]){
			for(int ee = 0; ee < cp.size(); ++ee)
				vis[ee] = 1;
			cp.clear();
		}
		cycle(v,eid);
	}
	if(!cannxt) cp.pop_back();
	tag[u] = 0;
}*/

void dfs(int u,int pre = -1,int flag = 0){
	for(int i = 0; i < G[u].size(); ++i){
		pii nxt = G[u][i];
		int eid = nxt.second, v = nxt.first;
		if(vis[eid] || (pre != -1 && E[pre].u == v)) continue;
		vis[eid] = 1;
		ans[eid] = flag;
		dfs(v,eid,flag);
		flag ^= 1;
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i = 0; i < m; ++i){
			int uu,vv;
			scanf("%d%d",&uu,&vv);
			if(uu == vv) continue;
			E[e].u = uu, E[e].v = vv, E[e++].id = i;
		}
		multiedge();
		ee = 0;
		for(int i = 0; i < e; ++i){
			if(vis[E[i].id]) continue;
			addedge(E[i]);
		}
	//	cycle(1);
		dfs(1);
		for(int i = 0; i < m; ++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}

