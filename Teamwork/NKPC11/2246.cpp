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
#include <ctime>
using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

double dp[203][2][203][103];
//第i层放j , 此时有k层交错，此时剩余z个1的概率为dp[i][j][k][z]
int main(){
	int n;
	while(~scanf("%d",&n)){
	memset(dp,0,sizeof(dp));
	dp[1][0][1][n] = 0.5; dp[1][1][1][n-1] = 0.5;
	for(int i = 2; i <= 2*n; ++i)
		for(int k = 1; k <= i; ++k){
			for(int z = n; z >= 0; --z){
				if(i - 1 - n + z == n){
					dp[i][1][k][z-1] = dp[i-1][0][k-1][z] + dp[i-1][1][k][z]; continue;
				}
				if(z == 0){
					dp[i][0][k][z] = dp[i-1][1][k-1][z] + dp[i-1][0][k][z]; continue;
				}
				dp[i][1][k][z-1] = 0.5 * (dp[i-1][0][k-1][z] + dp[i-1][1][k][z]);
				dp[i][0][k][z] = 0.5 * (dp[i-1][1][k-1][z] + dp[i-1][0][k][z]);
			}
		}
	double ans = 0;
	for(int i = 0; i <= 2*n; ++i){
		ans += 2*dp[2*n][0][i][0]*i;
	}
	printf("%.6lf\n",ans);
	}
    return 0;
}


