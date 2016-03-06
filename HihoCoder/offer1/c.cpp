#include <bits/stdc++.h>

using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3fll;

int n, m, k, t;
long long dp[10010];
int v[110], w[110];

long long solve(){
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < m; ++i){
		if(!v[i]) continue;
		for(int j = v[i]; j <= k; ++j){
			dp[j] = min(dp[j - v[i]] + w[i], dp[j]);
		}
	}
	long long res = dp[k];
	for(int i = 0; i < m; ++i){
		for(int j = 0; j <= k; ++j){
			if(j + v[i] >= k)
				res = min(res, dp[j] + w[i]);
		}
	}
	return res;
}

bool check(){
	int mx = 0;
	for(int i = 0; i < m; ++i){
		v[i] /= t;
		mx = max(v[i], mx);
	}
	return mx > 0;
}

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%d%d%d%d", &n, &m, &k, &t);
		for(int i = 0; i < m; ++i){
			scanf("%d", w + i);
		}
		for(int i = 0; i < m; ++i){
			scanf("%d", v + i);
		}
		long long ans = 0;
		for(int i = 0; i < n; ++i){
			if(i && !check()){
				ans = -1;
				break;
			}
			else
				ans += solve();
		}
		if(ans < 0) puts("No Answer");
		else cout << ans << '\n';
	}
	return 0;
}

