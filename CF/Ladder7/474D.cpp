#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int dp[100010], sum[100010];

int main(){
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	int n, k;
	cin >> n >> k;
	for(int i = 0; i <= 100000; ++i){
		dp[i] = i < k ? 1 : (dp[i-k] + dp[i-1]) % mod;
		if(i != 0)
			sum[i] = (sum[i-1] + dp[i]) % mod;
	}
	int u, v;
	for(int i = 0; i < n; ++i){
		cin >> u >> v;
		cout << ((sum[v] - sum[u-1] + mod) % mod) << '\n';
	}
	return 0;
}
