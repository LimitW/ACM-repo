/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
*************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 505;
const int maxm = 1e5 + 10;
long long need[maxn],val[maxn];
long long dp[maxm];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++)
		scanf("%lld%lld",&need[i],&val[i]);
	memset(dp,0,sizeof(dp));
	long long ans = -1;
	for(int i = 1; i <= n; i++)
		for(int j = need[i]; j <= m; j++)
            dp[j-need[i]] = max(dp[j]+val[i],dp[j-need[i]]);
    for(int j = 0; j <= m; j++)
        ans = max(ans,dp[j]);
	printf("%lld\n",ans);
	return 0;
}