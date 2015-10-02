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
const int maxn = 1e6 + 4;
//const int maxm = maxn * maxn;

int dp[1005][2005];
int a[1005], b[1005], w[1005];

int main(){
	int T; scanf("%d", &T);
	while(T--){
		memset(dp, 0, sizeof(dp));
		int n, m; scanf("%d%d", &m, &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d%d%d", &w[i], &a[i], &b[i]);
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j <= m; ++j){
				dp[i][j] = dp[i-1][j];
				if(j < w[i]) continue;
				dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+a[i]+b[i]);
				dp[i][j] = max(dp[i][j],dp[i][j-w[i]]+a[i]);
			}
		}
		int ans = 0;
		for(int i = 0; i <= m; ++i)
			ans = max(ans, dp[n][i]);
		printf("%d\n", ans);
	}
    return 0;
}

