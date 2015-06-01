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

int dp[1010][2<<10];
int w[1010];

int countq(int x)
{
	int ans = 0;
	while(x)
	{
		ans += (x & 1);
		x >>= 1;
	}
	return ans;
}

int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1; i <= n; i++)
		scanf("%d",&w[i]);
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i++)
		for(int s = 0; s < (1<<m-1); s++)
		{
			if(countq(s) >= q)
            {
                dp[i+1][s>>1] = max(dp[i+1][s>>1],dp[i][s]);
            }
			else
            {
                dp[i+1][(s>>1)+(1<<m-2)] = max(dp[i+1][(s>>1)+(1<<m-2)],dp[i][s] + w[i]);
                dp[i+1][s>>1] = max(dp[i+1][s>>1],dp[i][s]);
			}
		}
	int ans = -1;
    for(int s = 0; s < (1<<m-1); s++)
        ans = max(ans,dp[n+1][s]);
	printf("%d\n",ans);
	return 0;
}