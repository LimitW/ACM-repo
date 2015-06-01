/*
 * Title:Little Tiger vs. Deep Monkey
 * Author:LimitW
 * Date:2014.7.25
 * Source:2013 ChangChunSite C
 * Note:dp 答前i道题得j分的概率为dp[i][j]
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
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

const int MAXN = 40010;
double dp[50][MAXN];
int a[MAXN];

int main(){	
	int T;
	cin>>T;
	while(T--){
		int n;
		double P;
		cin>>n>>P;
		int i,j;
		int sum=0;
		for(i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(i=0;i<n;i++){
			for(j=0;j<=sum;j++){
				if(dp[i][j] > 0){
					dp[i+1][j+a[i]] += dp[i][j]*0.5;
					dp[i+1][j] += 0.5*dp[i][j];
				}
			}
		}
		double cnt = 0;
		int ans;
		for(j=0;j<=sum;j++){
			cnt += dp[n][j];
			if(cnt >= P){
				ans = j;
				break;
			}
		}
		printf("%d\n",ans);

	}
	return 0;
}