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

LL dp[1 << 16];
int a[18];

int main(){
	int T; scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase){
		memset(dp, 0, sizeof(dp));
		memset(a, 0, sizeof(a));
		int n; scanf("%d", &n);
		char s[20];scanf("%s", s);
		int mega = 0;
		for (int j = 0; j < n; ++j)
			if (s[j] == '1') mega += 1 << j;
		for (int i = 0; i < n; ++i){
			scanf("%s", s);
			for (int j = 0; j < n; ++j){
				if (s[j] == '1') a[j] += 1 << i;
			}
		}
		int sz = 1 << n;
		dp[0] = 1LL;
		for (int i = 1; i < sz; ++i){
			int tmp = i, j = 0;
			while (tmp > 0){
				if (tmp & 1){
					int pre = (i - (1 << j));
					if ((mega & (1 << j)) || (pre & a[j]))
						dp[i] += dp[pre];
				}
				tmp >>= 1;
				++j;
			}
		}
		printf("Case %d: %lld\n", kase, dp[sz - 1]);
	}
	return 0;
}
