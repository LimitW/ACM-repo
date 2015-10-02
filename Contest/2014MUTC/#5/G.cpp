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

int n , m , t;
int G[45][45] , vis[45];
int topo[45];

bool dfs(int u){
	vis[u] = -1;
	for(int v = 1; v <= n; v++)
	{
		if(vis[v] < 0) return false;
		else if(!vis[v] && !dfs(v)) return false;
	}
	vis[u] = 1; topo[--t] = u;
	return true;
}

bool toposort()
{
	t = n;
	memset(vis,0,sizeof(vis));
	for(int u = 1; u <= n; u++)
	{
		if(!dfs(u)) return false;
	}
	return true;
}

int main(){
	//freopen("test.in","r",stdin);
	while(scanf("%d %d",&n,&m) != EOF) {
		for(int i = 0; i < m; i++)
		{
			int u , v; scanf("%d %d",&u,&v);
			G[u][v] = 1;
		}
		toposort();
	}
	return 0;
}
