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
const int maxn = 2e4 + 3;
const int maxm = 2e5 + 3;
const double eps = 1e-9;

int mp[110][110];

int main(){
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		memset(mp, 0, sizeof(mp));
		for(int i = 0; i < m; ++i){
			int u, v; scanf("%d%d", &u, &v);
			mp[u][v] = mp[v][u] = 1;
		}
		int ans = 1;
		if(mp[1][n]) ans = n * (n - 1) / 2;
		printf("1 %d\n", ans);
	}
	return 0;
}

