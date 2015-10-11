#include <bits/stdc++.h>

using namespace std;

const int maxn = 47000;

int n, mod;

int dp[maxn], ans[maxn];

int cycle(){
	ans[0] = 2; ans[1] = 10;
	for(int i = 2; i < maxn; ++i){
		ans[i] = (10 * ans[i-1] - ans[i-2] + mod) % mod;
		if(ans[i] == ans[1] && ans[i-1] == ans[0]){
			dp[mod] = i - 1;
			return dp[mod];
		}
	}
}

int pmod(int a, int b, int mod){
	int ans = 1, tmp = a;
	while(b > 0){
		if(b & 1) ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		b >>= 1;
	}
	return ans;
}

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%d%d", &n, &mod);
		int r = (1 + pmod(2, n, cycle())) % mod;
		printf("Case #%d: %d\n", kase, (ans[r] - 1 + mod) % mod);
	}
	return 0;
}

