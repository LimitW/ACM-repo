/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
*************************************************/

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

int head[maxn],c;

struct edge{
	int u,v,w;
	int nxt;
}e[maxm];

void addedge(int u,int v,int w){
	e[c].u = u; e[c].v = v; e[c].w = w;
	e[c].nxt = head[u]; head[u] = c++;
}



int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) && (n || m)){
		for(int i = 1; i <= n; i++){
			int a,b; scanf("%d%d",&a,&b);
			addedge(0,i,a); addedge(i,n+1,b);
		}
		for(int i = 1; i <= m; i++){
			int u,v,w; scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w); addedge(v,u,w);
		}
		printf("%d\n",maxFlow);
	}
	return 0;
}