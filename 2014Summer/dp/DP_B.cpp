/*
 * Title:
 * Author:LimitW
 * Date:2014.8.20
 * Source:Uvaoj 10163
 * Note:dp 背包 滚动数组
*/

//f[i][j]表示前i个人管理j个仓库最大安全值
//g[i][j]表示最大安全值下所用最小花费
//仓库数量n看作背包容量，看守者看作物品，价值为p[i]/k，k为其所看守的仓库数量。

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

int n,m;
int p[35];
int f[105],g[105];

int main(){
	while(cin >> n >> m && (n || m)){
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		int i,j,k;
		f[0] = 1<<30;
		for(i = 1; i <= m; i++)
			cin >> p[i];
		for(i = 1; i <= m; i++)
			for(j = n; j >= 0; j--)
				for(k = 1; k <= j; k++)
					f[j] = max(f[j],min(p[i] / k,f[j - k]));
		int l = f[n];
		if(l == 0){
			printf("0 0\n");
			continue;
		}
		for(i = 1; i <= n; i++)
			g[i] = 1<<30;
		for(i = 1; i <= m; i++)
			for(j = n; j >= 0; j--)
				for(k = min(j, p[i] / l); k > 0; k--)
					g[j] = min(g[j],g[j - k] + p[i]);
		int y = g[n];
		printf("%d %d\n",l,y);
	}
	return 0;
}