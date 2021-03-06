//============================================================================
// Name        : UVa103.cpp
// Author      : LimitW
// Date        : 2014.11.20
// Version     :
// Copyright   : UVa10635
// Description : DAG dp/LIS
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

int n,k;

struct nd{
	int a[11];
	void _sortnd(){ sort(a,a+n); }
	bool is_match(nd b){
		for(int i = 0; i < n; i++)
			if(a[i] >= b.a[i]) return 0;
		return 1;
	}
}sq[32];

int d[32];
bool g[32][32];

int dp(int i){
	int &ans = d[i];
	if(ans > 0) return ans;
	ans = 1;
	for(int j = 1; j <= k; j++)
		if(g[i][j]) ans = max(ans,dp(j)+1);
	return ans;
}

void print_path(int i){
	printf("%d%c", i , d[i] == 1 ? '\n' : ' ');
	for(int j  = 1; j <= k; j++)
		if(g[i][j] && d[i] == d[j] + 1)
		{ print_path(j); break; }
	return;
}

int main(){
	while(scanf("%d%d",&k,&n) != EOF){
		memset(d,0,sizeof(d));
		memset(g,0,sizeof(g));
		for(int i = 1; i <= k; i++){
			for(int j = 0; j < n; j++)
				scanf("%d",&sq[i].a[j]);
			sq[i]._sortnd();
		}
		for(int i = 1; i <= k; i++)
			for(int j = 1; j <= k; j++){
					if(i == j) continue;
					g[i][j] = sq[i].is_match(sq[j]);
			}
		int ans = 0 , pos = 0;
		for(int i = 1; i <= k; i++){
			d[i] = dp(i);
			if(d[i] > ans) { ans = d[i]; pos = i; }
		}
		printf("%d\n",ans);
		print_path(pos);
	}
	return 0;
}

//LIS O(N^2)
/*
int n,k;

struct nd{
	int a[11] , id;
	void _sortnd(){ sort(a,a+n); }
	bool is_match(nd b){
		for(int i = 0; i < n; i++)
			if(a[i] >= b.a[i]) return 0;
		return 1;
	}
	bool operator < (nd b) const {
		for(int i = 0; i < n; i++)
			if(a[i] == b.a[i]) continue;
			else if(a[i] < b.a[i]) return 1;
			else return 0;
		return 1;
	}
}sq[32];

int dp[32] , nxt[32] , path[32];

int main(){
	while(scanf("%d%d",&k,&n) != EOF){
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= k; i++){
			for(int j = 0; j < n; j++)
				scanf("%d",&sq[i].a[j]);
			sq[i]._sortnd(); sq[i].id = i;
		}
		sort(sq,sq+k);
		for(int i = 1; i <= k; i++){
			dp[i] = 1; nxt[i] = -1;
			for(int j = 1; j <= k; j++){
					if(sq[j].is_match(sq[i]) && dp[j] + 1 > dp[i])
					{ dp[i] = dp[j] + 1; nxt[i] = j; }
			}
		}
		int ans = 0 , pos = 0;
		for(int i = 1; i <= k; i++)
			if(ans < dp[i]) { pos = i; ans = dp[i]; }
		printf("%d\n",ans);
		int c = ans;
		for(int e = pos; e != -1; e = nxt[e])
			path[--c] = sq[e].id;
		for(int i = 0; i < ans; i++)
			printf("%d%c",path[i], i == ans-1 ? '\n' : ' ');
	}
	return 0;
}*/
