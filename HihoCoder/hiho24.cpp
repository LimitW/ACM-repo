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
const int maxn = 110;

int d[maxn][maxn];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			d[i][j] = i == j ? 0 : INF;
	for(int i = 0; i < m; i++){
		int uu,vv,ww; scanf("%d%d%d",&uu,&vv,&ww);
		d[uu][vv] =min(d[uu][vv],ww);
		d[vv][uu] = d[uu][vv];
	}
	for(int k = 1; k <= n; k++) // k在最外层
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			printf("%d%c",d[i][j], j == n ? '\n' : ' ');
		}
	return 0;
}

