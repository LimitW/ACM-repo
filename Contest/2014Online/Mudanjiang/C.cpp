/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.9.7
 * Source:2014 Mudanjiang Online C
 * Note:dfs 是否存在一条按顺序访问部分节点并可遍历全图的路径
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
const int maxn = 100010;

vector<int> G[maxn];
bool sensor[maxn];
int CatchNo[maxn];
bool vis[maxn];

void dfs(int u){
	vis[u] = 1;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		if(!vis[v] && !sensor[v])
			dfs(v);
	}
}

int main(){
		int T;
	cin >> T;
	int n,m,k,l;
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i = 0; i < n; i++)
			G[i].clear();
		memset(sensor,0,sizeof(sensor));
		for(int i = 0; i < k; i++){
			int No; cin >> No;
			sensor[No-1] = 1;
		}
		for(int i = 0; i < m; i++){
			int No1,No2;
			cin >> No1 >> No2;
			No1--; No2--;
			G[No1].push_back(No2);
			G[No2].push_back(No1);
		}
		cin >> l;
		for(int i = 0; i < l; i++){
			int tmp; cin >> tmp;
			CatchNo[i] = tmp - 1;
		}
		int ans = 1;
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < l-1; i++){
			dfs(CatchNo[i]);
			bool flag = 0;
			for(int j = 0; j < G[CatchNo[i+1]].size(); j++)
				if(vis[G [ CatchNo[i+1]] [j] ]) { flag = 1; break; }
			if(!flag) { ans = 0; break; }
		}
		dfs(CatchNo[l-1]);
		int ans_ = 0;
		for(int j = 0; j < G[CatchNo[l-1]].size(); j++)
			if(vis[G[CatchNo[l-1]][j]]){ ans_ = 1; break; }
		if(!ans_) ans = 0;
		for(int i = 0; i < n; i++)
			if(!vis[i]){ ans = 0; break; }
		if(ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}