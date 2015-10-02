/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
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
#include <utility>
#include <algorithm>

using namespace std;

#define pii pair<int,int>

const int INF = 0x3f3f3f3f;


int mp[120][120];
priority_queue<pii,vector<pii>,greater<pii> > pq;
bool vis[120];

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
	memset(vis,0,sizeof(vis));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			scanf("%d",&mp[i][j]);
		}
	int ans = 0 , s = 1;
	vis[1] = true;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	for(int i = 2; i <= n; i++){
		pq.push(make_pair(mp[1][i],i));
	}
	while(s < n){
		pii tmp = pq.top(); pq.pop();
		int v = tmp.second;
		if(vis[v]) continue;
		vis[v] = true; ans += tmp.first; s++;
		for(int i = 1; i <= n; i++){
			if(vis[i] || i == v) continue;
			pq.push(make_pair(mp[v][i],i));
		}
	}
	printf("%d\n",ans);
	}
	return 0;
}