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
const double pi = acos(-1.0);
const long double eps = 1e-9;

const int maxn = 201314 + 1;
const LL mod = 530600414;
LL dp[maxn][4];

int main(){
	dp[2][0] = 2; dp[3][0] = 3; //length
	dp[2][1] = 0; dp[3][1] = 1; //cff times
	dp[2][2] = 0; dp[3][2] = 1; //cff total pos
	dp[2][3] = 0; dp[3][3] = 0; //ans
	for(int i = 4; i < maxn; ++i){
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][0] %= mod;
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
		dp[i][1] %= mod;
		dp[i][2] = dp[i-2][2] + dp[i-1][2] + dp[i-1][1] * dp[i-2][0];
		dp[i][2] %= mod;
		dp[i][3] = (dp[i-1][3] + dp[i-2][3]) % mod +
				(((dp[i-1][2] + dp[i-1][1] * dp[i-2][0]) % mod) * dp[i-2][1]) % mod
				- (dp[i-2][2] * dp[i-1][1]) % mod;
		while(dp[i][3] < 0) dp[i][3] += mod;
		dp[i][3] %= mod;
	}
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		int n; scanf("%d", &n);
		printf("Case #%d: %lld\n", kase, dp[n][3]);
	}
    return 0;
}

