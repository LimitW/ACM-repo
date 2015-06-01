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
const int maxn = 100 + 5;

struct edge{
	int nxt,to;
}e[2*maxn];

int head[maxn] , dp[maxn][maxn], c = 0;

void addedge(int u,int v){
	e[++c].to = v;
	e[c].nxt = head[u];
	head[u] = c;
}

int n,m;

void dfs(int u,int fa){
	for(int i = head[u]; i != -1; i = e[i].nxt){
		if(e[i].to != fa) {
			int v = e[i].to; dfs(v,u);
			for(int j = m; j > 1; j--)
				for(int k = 1; k < j; k++)
				dp[u][j] = max(dp[u][j] , dp[u][j-k] + dp[v][k]);
		}
	}
}

int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++)
		scanf("%d",&dp[i][1]);
	for(int i = 1; i < n; i++){
		int u,v; scanf("%d%d",&u,&v);
		addedge(u,v); addedge(v,u);
	}
	dfs(1,-1);
	printf("%d\n",dp[1][m]);
	return 0;
}
