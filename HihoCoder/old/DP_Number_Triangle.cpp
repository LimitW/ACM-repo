#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

int dp[100+10][6000];
int Map[100+10][100+10];

int main(){
	memset(dp,0,sizeof(dp));
	int n;
	cin>>n;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++){
			cin>>Map[i][j];
		}
	dp[0][0] = Map[0][0];
	for(i=1;i<n;i++)
		for(j=0;j<=i;j++){
			if(j == i){
				dp[i][j] = Map[i][j] + dp[i-1][j-1]; continue;
			}
			if(j == 0){
				dp[i][j] = Map[i][j] + dp[i-1][j]; continue;
			}
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + Map[i][j];
		}

	int ans = dp[n-1][0];
	for(i=1;i<n;i++)
		ans = max(ans,dp[n-1][i]);
	cout<<ans<<endl;
	return 0;
}