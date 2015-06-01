#include <iostream>
#include <iomanip>
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
#include <utility>
#include <bitset>
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long

const int mod = 1000000007;

int dp[2010][2010];

int main(){
	freopen("winning_at_sports.txt","r",stdin);
	freopen("C.txt","w",stdout);
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; kase++)
	{
		int a,b; scanf("%d-%d",&a,&b);
		int ans1,ans2;
		memset(dp,0,sizeof(dp));
		dp[1][0] = 1;
		for(int i = 1; i <= a; i++)
			for(int j = 0; j <= b; j++)
			{
				if(j >= i) break;
				dp[i+1][j] += dp[i][j]; dp[i+1][j] %= mod;
				if(i > j + 1) { dp[i][j+1] += dp[i][j]; dp[i][j+1] %= mod; }
			}
		ans1 = dp[a][b];
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int i = 0; i <= b; i++)
			for(int j = 0; j <= b; j++)
			{
				if(i > j) continue;
				dp[i][j+1] += dp[i][j]; dp[i][j+1] %= mod;
				if(i + 1 <= j) { dp[i+1][j] += dp[i][j]; dp[i+1][j] %= mod; }
			}
		ans2 = dp[b][b];
		printf("Case #%d: %d %d\n",kase,ans1,ans2);
	}
    return 0;
}
