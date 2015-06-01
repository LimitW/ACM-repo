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

int flow[210][210] , cap[210][210] , p[210] , a[210];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) == 2){
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		memset(p,0,sizeof(p));
		for(int  i = 1; i <= n; i++){
			int s,e,c; scanf("%d%d%d",&s,&e,&c);
			cap[s][e] += c;
		}
		int f = 0;
		queue<int> q;
		for( ; ; ){
			memset(a,0,sizeof(a));
			a[1] = INF; q.push(1);
			while(!q.empty()){
				int tmp = q.front(); q.pop();
				for(int i = 1; i <= m; i++){
					if(!a[i] && cap[tmp][i] > flow[tmp][i]){
						p[i] = tmp; a[i] = min(a[tmp],cap[tmp][i] - flow[tmp][i]);
						q.push(i);
					}
				}
			}
			if(a[m] == 0) break;
			for(int u = m; u != 1; u = p[u]){
				flow[p[u]][u] += a[m];
				flow[u][p[u]] -= a[m];
			}
			f += a[m];
		}
		printf("%d\n",f);
	}
    return 0;
}

