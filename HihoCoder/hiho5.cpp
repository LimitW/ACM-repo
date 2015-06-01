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
const int maxn = 205;

int dp[maxn][maxn],maze[maxn][maxn];

int main(){
	int n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			scanf("%d",&maze[i][j]);
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++){
			dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]);
			dp[i][j] += maze[i][j];
		}
	int ans = -1;
	for(int i = 1; i <= n; i++)
		ans = max(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}
