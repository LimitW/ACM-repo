/*
 * Title:01背包
 * Author:LimitW
 * Date:2014.8.11
 * Source:Hiho一下 week 6
 * Note:01背包问题
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

long long value[500+10];
long long need[500+10];

int main(){
	int N,M;
	cin>>N>>M;
	long long dp[200000 +10];
	int i,j;
	for(i=0;i<N;i++)
		scanf("%I64d%I64d",&need[i],&value[i]);
	for(i=0;i<N;i++)
		for(j=M;j>=need[i];j--)
			dp[j] = max(dp[j],dp[j-need[i]]+value[i]);
	cout<<dp[M]<<endl;
	return 0;
}