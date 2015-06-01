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

const int INF = 0x3fffffff;
const int maxn = 1e3 + 3;

int d[maxn] , mp[maxn][maxn] , vis[maxn];
int n,m,s,t;

int main(){
	memset(mp,-1,sizeof(mp));
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i = 1; i <= n; i++) d[i] = INF;
	for(int i = 0; i < m; i++){
		int uu,vv,ww; scanf("%d%d%d",&uu,&vv,&ww);
		mp[uu][vv] = mp[uu][vv] != -1 ? min(mp[uu][vv],ww) : ww;
		mp[vv][uu] = mp[uu][vv];
	}
	d[s] = 0; //选择当前集合连通点的最短边，可堆优化
	for(int i = 1; i <= n; i++){
			int x,m = INF;
			for(int y = 1; y <= n; y++)
				if(!vis[y] && d[y] <= m)
				{ x = y; m = d[x]; }
			vis[x] = 1;
			for(int y = 1; y <= n; y++){
				if(mp[x][y] != -1)
					d[y] = min(d[y] , d[x] + mp[x][y]);
			}
	}
	printf("%d\n",d[t]);
	return 0;
}

