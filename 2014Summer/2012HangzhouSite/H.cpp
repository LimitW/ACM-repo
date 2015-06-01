/*
 * Title:Friend Chains
 * Author:LimitW
 * Date:2014.8.4
 * Source:2012 HangZhouSite H
 * Note:最短路问题 对每个点bfs
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

#define INF 1000000

map <string,int> mp;
vector <int> vec[1010];
queue <int> que;                  
int dis[1010][1010];
bool vis[1010];

void bfs(int i){
	memset(vis,0,sizeof(vis));
	dis[i][i] = 0;
	vis[i] = 1;
	que.push(i);
	while(!que.empty()){
		int x = que.front();
		que.pop();
		int j;
		for(j=0;j<vec[x].size();j++){
			int t = vec[x][j];
			if(!vis[t]){
				vis[t] = 1;
				dis[i][t] = dis[i][x] + 1;
				que.push(t);
			}
		}
	}
}

int main(){
	int N;
	string a,b;
	while(scanf("%d",&N) && N){
		mp.clear();
		int i,j;
		for(i=0;i<N;i++){
			dis[i][i] = 0;
			for(j=i+1;j<N;j++)
				dis[i][j] = INF;
		}
		for(i=0;i<N;i++){
			cin>>a;
			mp[a] = i;
		}
		int M;
		scanf("%d",&M);
		for(i=0;i<N;i++)
			vec[i].clear();
		for(i=0;i<M;i++){
			cin>>a>>b;
			int t1 = mp[a];
			int t2 = mp[b];
			vec[t1].push_back(t2);
			vec[t2].push_back(t1);
		}
		for(i=0;i<N;i++)
			bfs(i);
		int ans = 0;

		for(i=0;i<N;i++)
			for(j=i+1;j<N;j++)
				ans = max(ans,dis[i][j]);
		if(ans == INF) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}