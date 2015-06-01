/*
 * Title:Pashmak and Graph
 * Author:LimitW
 * Date:2014.8.16
 * Source:codeforces round 261 E
 * Note:dp 图论
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

int edgedp[300010],nodedp[300010]; //dp[i]对点dp,dp2对边dp

struct edge
{
	int Beginpoint,Endpoint;
	int edgeLength;
}e[300010];

bool cmp(const edge a,const edge b){
	return a.edgeLength < b.edgeLength;
}

int main(){
	memset(edgedp,0,sizeof(edgedp));
	memset(nodedp,0,sizeof(nodedp));
	int n,m;
	cin>>n>>m;
	int i,j,k;
	for(i=0;i<m;i++){
		scanf("%d%d%d",&e[i].Beginpoint,&e[i].Endpoint,&e[i].edgeLength);
	}
	sort(e,e+m,cmp);
	for(i=0;i<m;i++){
		j = i;
		// update edgedp
		while(j <= m && e[i].edgeLength == e[j].edgeLength){
			int x = e[j].Beginpoint;
			edgedp[j] = max(edgedp[j],nodedp[x]+1);
			j++;
		}
		j = i;
		// update nodedp
		while(j <= m && e[i].edgeLength == e[j].edgeLength){
			int y = e[j].Endpoint;
			nodedp[y] = max(nodedp[y],edgedp[j]);
			j++;
		}
		i = j - 1;
	}
	int ans = 0;
	for(i=0;i<m;i++){
		ans = max(ans,edgedp[i]);
	}
	printf("%d\n",ans);
	return 0;
}