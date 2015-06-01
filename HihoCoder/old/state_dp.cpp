/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.8.25
 * Source:Hihocoder week 8
 * Note:状态压缩dp
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

int dp[1010][(1<<10)+10];
int n,m,q;
int w[1010];

int get_state(int x){
	int countx = 0;
	for(countx = 0; x; x >>= 1)
		countx += x & 1;
	return countx;
}

int main(){
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++)
		for(int j = (1 << m) - 1; j >= 0; j--){
			if(get_state(j>>1) <= q)
				dp[i][j>>1] = max(dp[i][j>>1],dp[i-1][j]);
			if(get_state(j>>1) < q)
				dp[i][(j>>1)|(1<<(m-1))] = max(dp[i][(j>>1)|(1<<(m-1))],dp[i-1][j]+w[i]);
		}
	int ans = 0;
	for(int i = 0; i < (1 << m); i++)
		ans = max(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}