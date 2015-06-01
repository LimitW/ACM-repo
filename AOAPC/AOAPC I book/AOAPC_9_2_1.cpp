/*
 * Title:
 * Author:LimitW
 * Date:2014.8.20
 * Source:AOAPC I
 * Note:DAG上的动态规划 嵌套矩形 记忆化搜索
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

struct mat
{
	int x,y;
}m[100];

int G[100][100];
int d[100];
int n;

int dp(int i){
	int& ans = d[i];
	if(ans > 0) return ans;
	ans = 1;
	int j;
	for(j = 1; j <= n; j++)
		if(G[i][j])
            ans = max(ans,dp(j)+1);
	return ans;
}

void print_ans(int i){
	printf("%d ",i);
	int j;
	for(j = 1; j <= n; j++)
		if(G[i][j] && d[i] == d[j] + 1){
			print_ans(j);
			break;
	}
}

int main(){
	memset(d,0,sizeof(d));
	memset(G,0,sizeof(G));
	cin >> n;
	int i,j;
	for(i = 1; i <= n; i++)
		cin >> m[i].x >> m[i].y;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if((m[i].x < m[j].x && m[i].y < m[j].y) || (m[i].y < m[j].x && m[i].x < m[j].y))
				G[i][j] = 1;
    /* test G[i][j]
    for(i = 1; i <= n; i++)
        for(j = 1; j<=n; j++)
            printf("No %d and No %d is %d.\n",i,j,G[i][j]);
    */
	for(i = 1; i <= n; i++)
		dp(i);
	int ans = 0,ans_i;
	for(i = 1; i <= n; i++){
		if(ans < d[i]) { ans = d[i]; ans_i = i; }
	}
	printf("%d\n",ans);
	print_ans(ans_i);
	return 0;
}