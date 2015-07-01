#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

const int maxn = 500 + 3;

int n,m;
int indg[maxn];
vector<int> G[maxn],zeros,ans;

int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(indg,0,sizeof(indg));
		for(int i = 1; i <= n; ++i) G[i].clear();
		for(int i = 0; i < m; ++i){
			int u,v; scanf("%d%d",&u,&v);
			G[u].push_back(v);
		}
		for(int i = 1; i <= n; ++i){
            sort(G[i].begin(),G[i].end());
            unique(G[i].begin(),G[i].end());
            for(int j = 0; j < G[i].size(); ++j)
                ++indg[G[i][j]];
		}
		priority_queue<int,vector<int>,greater<int> > zeros;
		while(zeros.size() > 0) zeros.pop();
		ans.clear();
		for(int i = 1; i <= n; ++i){
			if(!indg[i]){
				zeros.push(i);
			}
		}
		while(zeros.size() > 0){
			int tp = zeros.top();
			zeros.pop();
			ans.push_back(tp);
			for(int j = 0; j < G[tp].size(); ++j){
				--indg[G[tp][j]];
				if(!indg[G[tp][j]]) zeros.push(G[tp][j]);
			}
		}
		for(int i = 0; i < n - 1; ++i){
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[n-1]);
	}
	return 0;
}
