//============================================================================
// Name        : F.cpp
// Author      : LimitW
// Date        : 2014.11.8
// Version     :
// Copyright   : 2013 Chengdu Onsite F
// Description : Graph Theory , Spanning Tree
//============================================================================
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <functional>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>
const int INF = 0x3f3f3f3f;

const int maxn = 1e5 + 5;

int fb[30] = {0};
void init(){
	fb[1] = 1; fb[2] = 1;
	for(int i = 3; i <= 25; i++)
	{
		fb[i] = fb[i-1] + fb[i-2];
	}
}

int n,m;

struct edge{
	int u,v,c;
}e[maxn];

bool cmp1(edge a,edge b){
	return a.c < b.c;
}

bool cmp2(edge a,edge b){
	return a.c > b.c;
}

int p[maxn];
int vis[maxn];

int find(int x){
	return p[x] == x ? x : p[x] = find(p[x]);
}

int Kruskal(){
	memset(vis,0,sizeof(vis));
	int ans = 0;
	for(int i = 1; i <= n; i++) p[i] = i;
	for(int i = 0; i < m; i++)
	{
		int x = find(e[i].u);
		int y = find(e[i].v);
		if(x != y) { ans += e[i].c; p[x] = y; vis[i] = 1;}
	}
	return ans;
}

int main(){
	init();
	int T; cin >> T;
	for(int CaseNo = 1; CaseNo <= T; CaseNo++)
	{
		scanf("%d%d",&n,&m);
		for(int i = 0; i < m; i++)
		{
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			e[i].u = u; e[i].v = v; e[i].c = c;
		}
		int fail = 1;
		sort(e,e+m,cmp1);
		int minw = Kruskal();
		sort(e,e+m,cmp2);
		int maxw = Kruskal();
		for(int i = 1; i <= 25; i++)
			if(fb[i] >= minw && fb[i] <= maxw)
			{ fail = 0; break; }
		int visnode[maxn];
		memset(visnode,0,sizeof(visnode));
		for(int i = 0; i < m; i++)
		{
			if(vis[i]) visnode[e[i].u] = visnode[e[i].v] = 1;
		}
		for(int i = 1; i <= n; i++)
			if(!visnode[i]) fail = 1;
		if(fail) printf("Case #%d: No\n",CaseNo);
		else printf("Case #%d: Yes\n",CaseNo);
	}
	return 0;
}
