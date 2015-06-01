/*
 * Title:
 * Author:LimitW
 * Date:2014.8.10
 * Source:Codeforces Round 260 Div2 C
 * Note:dp
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

long long dp[100010];
long long a[100010];

int main(){
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		int e;
		cin>>e;
		a[e]++;
	}
	dp[0] = 0;
	for(i=1;i<100010;i++){
		dp[i] = i * a[i];
		if(i>2)
			dp[i] += dp[i-2];
		dp[i] = max(dp[i],dp[i-1]);
	}
	cout<<dp[100010-1]<<endl;
	return 0;
}