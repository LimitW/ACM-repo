/*
 * Title:Josephina and RPG
 * Author:LimitW
 * Date:2014.7.28
 * Source:2013 ChangShaSite J
 * Note:dp 打第i个敌人用第j种队伍的最优概率为dp[i][j]
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

int CombNum(int x){
	switch(x){
		case 3: return 1;
		case 4: return 4;
		case 5: return 10;
		case 6: return 20;
		case 7: return 35;
		case 8: return 56;
		case 9: return 84;
		case 10: return 120;
	}
	return 0;
}

double p[130][130];
int id[10010];
double dp[10010][130];

int main(){
	int M;
	while(scanf("%d",&M) != EOF){
		int i,j;
		int R = CombNum(M);
		for(i=0;i<R;i++)
			for(j=0;j<R;j++)
				scanf("%lf",&p[i][j]);
		int N;
		scanf("%d",&N);
		for(i=1;i<=N;i++)
			scanf("%d",&id[i]);
			for(i=0;i<=N;i++)
                for(j=0;j<=R;j++)
                    dp[i][j] = 0;
        for(i=0;i<R;i++)
            dp[N+1][i]=1.0;
		for(i=N;i>=1;i--){  //打第i个敌人用第j种队伍的最优概率为dp[i][j]
			for(j=0;j<R;j++)
				dp[i][j] = p[j][id[i]] * max(dp[i+1][j],dp[i+1][id[i]]);
		}
		double ans = 0;
		for(i = 0; i < R; i++)
			ans = max(ans,dp[1][i]);
		printf("%.6lf\n",ans);
	}
	return 0;
}