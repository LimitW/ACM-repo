#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
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

const int maxn = 2e5+5;

int n,m,e,qe,p[maxn];
map<string,int> mp;
char s[maxn][100];
int head[maxn] , nxt[2*maxn] , v[2*maxn] , vis[maxn];
int qhead[maxn] , qnxt[maxn] , qv[maxn] , ans[maxn];
//并查集没加路径压缩TLE半天。。。
int Find(int x){
	return p[x] == x ? x : p[x] = Find(p[x]);
}

void addEdge(int uu,int vv){
	v[++e] = vv; nxt[e] = head[uu]; head[uu] = e;
}

void addQEdge(int u,int v,int qe){
	qv[qe] = v; qnxt[qe] = qhead[u]; qhead[u] = qe;
}

void Tarjan(int u){
	vis[u] = 1;
	for(int e = head[u]; e != -1; e = nxt[e]){
			Tarjan(v[e]);
			p[v[e]] = u;
	}
	for(int q = qhead[u]; q != -1; q = qnxt[q]){
			if(vis[qv[q]]) ans[(q > m ? q - m : q)] = Find(qv[q]);
	}
}

int main(){
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
	memset(qhead,-1,sizeof(qhead));
	for(int i = 1; i <= maxn; i++) p[i] = i;
	int c = 0; e = 0; scanf("%d",&n);
	string a,b; char aa[100], bb[100];
	for(int i = 0; i < n; i++) {
		scanf("%s%s",aa,bb); a = aa; b = bb;
		if(mp.find(a) == mp.end()) { mp[a] = ++c; strcpy(s[c], aa);}
		if(mp.find(b) == mp.end()) { mp[b] = ++c; strcpy(s[c], bb); }
		addEdge(mp[a],mp[b]);
	}
	scanf("%d",&m);
	for(int i = 1; i <= m; i++) {
		scanf("%s%s",aa,bb); a = aa; b = bb;
		int uu = mp[a] , vv = mp[b];
		addQEdge(uu,vv,i); addQEdge(vv,uu,i+m);
	}
	Tarjan(1);
	for(int i = 1; i <= m; i++){
		printf("%s\n",s[ans[i]]);
	}
	return 0;
}

