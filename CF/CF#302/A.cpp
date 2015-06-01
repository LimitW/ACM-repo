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
#include <fstream>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const long long INFL = 1LL << 62;

int dp[2][510][510];
int a[510];

int main(){
	int n,m,b,mod;
	cin >> n >> m >> b >> mod;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	memset(dp,0,sizeof(dp));
	for(int j = 1; j <= n; ++j){
		dp[0][a[j]][j] = dp[0][a[j]][j-1] + 1;
		for(int i = j + 1; i <= n; ++i)
			dp[0][a[j]][i] = dp[0][a[j]][j];
	}
	int now = 1;
	for(int i = 2; i <= m; ++i){
		for(int k = 0; k <= b; ++k){
			for(int j = 1; j <= n; ++j){
				if(k >=a[j]) dp[now][k][j] = (dp[now^1][k-a[j]][j] + dp[now][k][j-1]) % mod;
				else dp[now][k][j] =dp[now][k][j-1];
			}
		}
		now ^= 1;
	}
	int ans = 0;
	for(int i = 0; i <= b; ++i){
		ans = (ans + dp[now^1][i][n]) % mod;
	}
	cout << ans << '\n';
	return 0;
}

