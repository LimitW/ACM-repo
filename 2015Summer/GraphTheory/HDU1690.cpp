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
const int maxn = 102;

LL dis[maxn][maxn];
LL L[4], C[4];
int n, m;
LL x[maxn];

void floyd(){
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j){
		if (i == j){
			dis[i][i] = 0;
			continue;
		}
		int id = lower_bound(L, L + 4, abs(x[j] - x[i])) - L;
		if (id > 3) dis[i][j] = dis[j][i] = INFL;
		else dis[i][j] = dis[j][i] = C[id];
		}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j){
		if (i == j || j == k || i == k) continue;
		dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
}

int main(){
	int T; scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase){
		for (int i = 0; i < 4; ++i)
			scanf("%I64d", &L[i]);
		for (int i = 0; i < 4; ++i)
			scanf("%I64d", &C[i]);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i){
			scanf("%I64d", &x[i]);
		}
		floyd();
		printf("Case %d:\n", kase);
		for (int i = 0; i < m; ++i){
			int u, v; scanf("%d%d", &u, &v);
			if (dis[u][v] >= INFL)
				printf("Station %d and station %d are not attainable.\n", u, v);
			else
				printf("The minimum cost between station %d and station %d is %I64d.\n", u, v, dis[u][v]);
		}
	}
	return 0;
}
