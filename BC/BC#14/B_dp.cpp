/************************************************
 * Title :
 * Author : LimitW
 * Date : 2014.10.26.
 * Source : BestCoder #14 B
 * Note : dp / dfs
*************************************************/

/* dp 15ms */

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

#define LL long long
#define pii pair<int,int>

vector<pii> v;
int dp[11][(1<<11)+10];

int dist(pii a, pii b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF){
    v.clear();
	for(int i = 1; i <= n; i++)
		for(int j = 1 ; j <= m; j++){
            int tmp; scanf("%d",&tmp);
			if( tmp != 0 && !(i == 1 && j == 1) ){ v.push_back(make_pair(i,j)); }
		}
	int N = v.size();
	if(N == 0){ printf("0\n"); continue;}
    pii o = make_pair(1,1);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < (1<<N); j++) dp[i][j] = INF;
    for(int i = 0; i < N; i++)
        dp[i][1<<i] = dist(v[i],o);
    for(int j = 0; j < (1<<N); j++)
        for(int i = 0; i < N; i++)
		{
		    if(dp[i][j] == INF) continue;
			for(int k = 0; k < N; k++)
			{
				if(((j>>k)&1) || (k==i)) continue;
				dp[k][j|(1<<k)] = min(dp[k][j|(1<<k)],dp[i][j]+dist(v[i],v[k]));
			}
		}
    //for(int i = 0; i < N; i++)
      //  for(int j = 0; j < (1<<N); j++)
        //    printf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
	int ans = INF;
	for(int i = 0; i < N; i++)
        ans = min(ans,dp[i][(1<<N)-1]+dist(v[i],o));
	printf("%d\n",ans);
	}
	return 0;
}
