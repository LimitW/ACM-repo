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

int n, m, num;
int s[65], c[65];
int a[110];
int dp[102][65][65];

void init(){
	memset(dp, 0, sizeof(dp));
	memset(a, 0, sizeof(a));
	num = 0;
	int sz = 1 << m;
	for (int i = 0; i < sz; ++i){
		int tmp = i, flag = 0;
		while (tmp > 0){
			if (tmp & 1){
				for (int j = 1; j < 3; ++j){
					if (tmp & (1 << j)) { flag = 1; break; }
				}
				if (!flag) tmp >>= 2;
			}
			else tmp >>= 1;
			if (flag) break;
		}
		if (!flag){
			tmp = i;
			c[num] = 0;
			while (tmp > 0){
				if (tmp & 1) ++c[num];
				tmp >>= 1;
			}
			s[num++] = i;
		}
	}
}

int main(){
	while (cin >> n >> m){
		init();
		for (int i = 0; i < n; ++i){
			string ss; cin >> ss;
			for (int j = 0; j < m; ++j)
				if (ss[j] == 'H') a[i] += (1<<j);
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < num; ++j)
				for (int k = 0; k < num; ++k){
			if (s[j] & a[i]) continue;
			int pre = 0;
			if (i == 1){
				if (!((s[j] & s[k]) || (s[k] & a[i - 1])))
					pre = c[k];
			}
			else if (i > 1){
				for (int l = 0; l < num; ++l){
					if ( !(s[l] & a[i-2]) && !(s[j] & s[k]) && !(s[j] & s[l]) && !(s[l] & s[k]))
						pre = max(pre, dp[i - 1][k][l]);
				}
			}
			dp[i][j][k] = pre + c[j];
				}
		int ans = 0;
		for (int i = 0; i < num; ++i)
			for (int j = 0; j < num; ++j)
				ans = max(ans, dp[n - 1][i][j]);
		cout << ans << '\n';
	}
	return 0;
}
