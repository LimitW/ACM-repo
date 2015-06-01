/*
 * Title:
 * Author:LimitW
 * Date:2014.8.20
 * Source:Hihocoder week 7
 * Note:完全背包 dp
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

long long dp[200010];
int v[510],w[510];
int C,n;

int main(){
	memset(dp,0,sizeof(dp));
	cin >> n >> C;
	int i,j;
	for(i = 1; i <= n; i++)
		cin >> v[i] >> w[i];
	/* TLE 未使用滚动数组
	for(i = 1; i <= n; i++)
		for(j = 0; j <= C; j++){
			if(v[i] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-v[i]]+w[i]); //重复利用已计算的dp[i][j-v[i]]
		}
	*/
	for(i = 1; i <= n; i++)
		for(j = 0; j <= C; j++){ //注意顺序,0-1背包是C->0,完全背包是0->C
			if(j >= v[i])
				dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
		}
	printf("%lld\n",dp[C]);
	return 0;
}