#include <bits/stdc++.h>

using namespace std;

int dp[100010][3][2];

int main(){
	int n; cin >> n;
	string s; cin >> s;
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 3; ++j)
			for(int k = 0; k < 2; ++k)
				dp[i+1][j][k] = dp[i][j][k];
		int cur = s[i] - '0';
		dp[i+1][0][cur] = max(dp[i+1][0][cur], dp[i][0][1^cur] + 1);
		dp[i+1][1][1^cur] = max(dp[i+1][1][1^cur], dp[i][1][cur] + 1);
		dp[i+1][1][1^cur] = max(dp[i+1][1][1^cur], dp[i][0][cur] + 1);
		dp[i+1][2][cur] = max(dp[i+1][2][cur], dp[i][1][1^cur] + 1);
		dp[i+1][2][cur] = max(dp[i+1][2][cur], dp[i][2][1^cur] + 1);
	}
	int ans = 0;
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 2; ++j)
			ans = max(ans, dp[n][i][j]);
	cout << ans << '\n';
    return 0;
}

