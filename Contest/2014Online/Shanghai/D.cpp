/************************************************
 * Title:Contest
 * Author:LimitW
 * Date:2014.9.27
 * Source:2014 Shanghai Online D
 * Note:状态压缩dp
*************************************************/

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

double p[10][1010];
double dp[1010][1<<10];
bool vis[1010][1<<10];
int n,m;

double solve(int id,int s){
	if(s == (1<<n)-1) s = 0;
	if(vis[id][s]) return dp[id][s];
	vis[id][s] = 1;
	dp[id][s] = 0;
	if(id == m)return dp[id][s];
	for(int i = 0;i < n;i++){
		if(s&(1<<i)) continue;
		dp[id][s] = max(dp[id][s],(1-p[i][id])*solve(id+1,s|(1<<i))+p[i][id]*(solve(id+1,s|(1<<i))+1));
	}
	return dp[id][s];
}

int main(){
	int T;
	scanf("%d",&T);
	for(int CaseNo = 1; CaseNo <= T; CaseNo++){
		scanf("%d%d",&n,&m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%lf",&p[i][j]);
		memset(vis,0,sizeof(vis));
		printf("Case #%d: %.5lf\n",CaseNo,solve(0,0));
	}
	return 0;
}