/*
 * Title:
 * Author:LimitW
 * Date:2014.8.20
 * Source:AOAPC I
 * Note:01背包 滚动数组
*/

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

//long long dp[510][200010];
long long dp[200010];
int v[510],w[510];
int C,n;

int main(){
	memset(dp,0,sizeof(dp));
	cin >> n >> C;
	int i,j;
	for(i = 1; i <= n; i++)
		cin >> v[i] >> w[i];
	/*TLE 未使用滚动数组
	for(i = 1; i <= n; i++)
		for(j = 0; j <= C; j++)
		{
			if(v[i] <= j)
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
			else
				dp[i][j] = dp[i-1][j];
		}
	*/
	for(i = 1; i <= n; i++)
		for(j = C; j >= 0; j--){//倒序计算，计算dp(i,j)前的dp[j] = dp[i-1][j]
			if(j >= v[i])
				dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
		}
	printf("%lld\n",dp[C]);
	return 0;
}