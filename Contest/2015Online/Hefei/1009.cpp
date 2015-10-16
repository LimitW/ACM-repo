#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int dp[31][31][1800], a[31][31];

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		int n, m; scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				scanf("%d", &a[i][j]);
		memset(dp, INF, sizeof(dp));
		dp[0][1][0] = 0;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				for(int k = 0; k + a[i][j] < 1800; ++k){
					if(dp[i-1][j][k] >= INF && dp[i][j-1][k] >= INF) continue;
					int v = min(dp[i-1][j][k], dp[i][j-1][k]) + a[i][j] * a[i][j];
					dp[i][j][k+a[i][j]] = min(dp[i][j][k+a[i][j]], v);
				}
		int ans = INF;
		for(int i = 0; i < 1800; ++i){
			if(dp[n][m][i] >= INF) continue;
			ans = min(ans, (n + m - 1) * dp[n][m][i] - i * i);
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}

