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

double dp[12][1025];
double mp[12][1010];
int n, m;

int main(){
	int T; scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase){
		memset(dp, 0, sizeof(dp));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%lf", &mp[i][j]);
		int sz = 1 << n;
		double ans = 0;
		for (int i = 1; i <= m; ++i){
			int ii = (i-1) % n;
			for (int j = 0; j < sz; ++j){
				double mx = 0;
				int tmp = j, cnt = 0;
				while (cnt < n){
					if (!(tmp & 1)){
						if (ii != 0)
							dp[ii][j | (1 << cnt)] = max(dp[ii][j | (1 << cnt)], dp[ii - 1][j] + mp[cnt][i]);
						else
							dp[ii][j | (1 << cnt)] = max(dp[ii][j | (1 << cnt)],mp[cnt][i]);
						//printf("dp[%d][%d]=%.5lf\n", ii, j | (1 << cnt), dp[ii][j | (1 << cnt)]);
					}
					tmp >>= 1;
					++cnt;
				}
			}
			if (i % n == 0){
				ans += dp[n - 1][sz - 1];
				memset(dp, 0, sizeof(dp));
			}
		}
		n = m % n;
		if (n == 0){
			printf("Case #%d: %.5lf\n", kase, ans);
			continue;
		}
		double mx = 0;
		for (int i = 0; i < sz; ++i){
			int tmp = i, dg = 0;
			while (tmp > 0){
				if (tmp & 1) ++dg;
				tmp >>= 1;
			}
			if (dg == n) mx = max(mx,dp[n-1][i]);
		}
		printf("Case #%d: %.5lf\n", kase, ans + mx);
	}
	return 0;
}
