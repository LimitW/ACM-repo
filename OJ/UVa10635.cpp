//============================================================================
// Name        : UVa10635.cpp
// Author      : LimitW
// Date        : 2014.11.21
// Version     :
// Copyright   : UVa10635
// Description : LCS -> LIS nlogn
//============================================================================
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

const int maxn = 250 + 5;

int a[maxn*maxn] , b[maxn*maxn];

/*
int dp[maxn][maxn];
int LCS(int* a,int* b,int p,int q){
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= p; i++)
		for(int j = 1; j <= q; j++)
		{
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	return dp[p][q];
}*/
int dp[maxn*maxn];

int LIS(int *a,int n)
{
	int k = 0; dp[0] = 0; //path[i] = -1;
	for(int i = 1; i < n; i++)
	{
		if(a[i] > a[dp[k]]){
			//path[i] = dp[k];
			dp[++k] = i;
		}
		else{
			int l = 0 , r = k + 1;
			while(l < r){
				int m = (l + r) / 2;
				if(a[i] > a[dp[m]]) l = m+1;
				else r = m;
			}
			dp[r] = i;
			//path[i] = (r==0) ? -1 : dp[r-1];
		}
	}
	return n == 0 ? 0 : k+1;
}

int num[maxn*maxn] , s[maxn*maxn];

int main(){
	int t; scanf("%d",&t);
	for(int kase = 1; kase <= t; kase++){
		memset(num,0,sizeof(num));
		int n,p,q; scanf("%d%d%d",&n,&p,&q);
		for(int i = 1; i <= p+1; i++) scanf("%d",&a[i]);
		for(int i = 1; i <= q+1; i++) scanf("%d",&b[i]);
		for(int i = 1; i <= p+1; i++) num[a[i]] = i;
		int N = 0;
		for(int i = 1; i <= q+1; i++){
			if(num[b[i]]) s[N++] = num[b[i]];
		}
		printf("Case %d: %d\n",kase,LIS(s,N));
	}
    return 0;
}
