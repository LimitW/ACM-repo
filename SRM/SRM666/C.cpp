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
const int maxn = 1 << 16;
//const int maxm = maxn * maxn;

class CollectingTokens{
public:
	vector<int> G[52];
	int dp[52][105][2];
	int a[maxn], l;

	void dfs(int u,int fa = -1){
		dp[u][0][0] = dp[u][0][1] = a[u];
		for(int i = 0; i < G[u].size(); ++i){
			int v = G[u][i];
			if(v == fa) continue;
			dfs(v,u);
			for(int j = l; j >= 0; --j){
				for(int k = 0; k <= l; ++k){
					if(j >= k + 2){
						dp[u][j][1] = max(dp[u][j][1], dp[u][j-k-2][1] + dp[v][k][1]);
						dp[u][j][0] = max(dp[u][j][0], dp[u][j-k-2][0] + dp[v][k][1]);
					}
					if(j >= k + 1){
						dp[u][j][0] = max(dp[u][j][0], dp[u][j-k-1][1] + dp[v][k][0]);
					}
				}
			}
		}
	}

	int maxTokens(vector<int> A, vector<int> B, vector<int> tokens, int L){
		int n = A.size() + 1;
		for(int i = 0; i < n; ++i)
			G[i].clear();
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n - 1; ++i){
			G[A[i]].push_back(B[i]);
			G[B[i]].push_back(A[i]);
		}
		l = L;
		for(int i = 0; i < n; ++i)
			a[i+1] = tokens[i];
		dfs(1);
		int ans = 0;
		for(int i = 0; i <= L; ++i)
			ans = max(ans, dp[1][i][0]);
		return ans;
	}
};
