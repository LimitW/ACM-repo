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

const int INF = 0x3f3f3f3f;

int dp[3010];

struct node{
	int A, B, C;
	bool operator < (node b) const{
		return 1ll * B * b.C > 1ll * b.B * C;
	}
}a[1010];

int main(){
	int T; scanf("%d", &T);
	while(T--){
		memset(dp, 0, sizeof(dp));
		int n, m; scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i){
			scanf("%d%d%d", &a[i].A, &a[i].B, &a[i].C);
		}
		sort(a, a + n);
		for(int i = 0; i < n; ++i){
			for(int j = m; j >= a[i].C; --j){
				dp[j] = max(dp[j], dp[j - a[i].C] + a[i].A - j * a[i].B);
			}
		}
		int ans = 0;
		for(int i = 0; i <= m; ++i)
			ans = max(ans, dp[i]);
		printf("%d\n", ans);
	}
    return 0;
}

