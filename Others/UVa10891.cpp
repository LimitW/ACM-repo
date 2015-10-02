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
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

int a[110],sum[110];
int dp[110][110];

int main(){
	int n;
	while(scanf("%d",&n) && n){
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&a[i]);
			sum[i] = sum[i-1] + a[i];
		}
		for(int i = 1; i <= n; i++)
			dp[i][i] = a[i];
		for(int k = 2; k <= n; k++)
		{
			for(int i = 1; i < n; i++)
			{
					int j = i + k - 1;
					if(j > n) continue;
					int tmp = 0;
					for(int t = i+1; t <= j; t++)
						tmp = min(tmp,dp[t][j]);
					for(int t = j; t >= i; t--)
						tmp = min(tmp,dp[i][t]);
					dp[i][j] = sum[j]-sum[i-1]-tmp;
			}
		}
		printf("%d\n",2 * dp[1][n] - sum[n]);
	}
    return 0;
}
