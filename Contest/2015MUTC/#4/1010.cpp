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
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 3;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int r,c,n,T,sdn;

struct sd{
	int x,y,d;
}q[1000];

bool bq[1000];
int vis[200][200];
pii dp[200];
pii ans[200];

void addsd(int xx,int yy,int dd){
	q[sdn].x = xx, q[sdn].y = yy, q[sdn].d = dd;
	++sdn;
}

int main(){
	while(~scanf("%d%d%d%d",&r,&c,&n,&T)){
		memset(vis,0,sizeof(vis));
		memset(bq,0,sizeof(bq));
		sdn = 0;
		int x,y,sz;
		for(int i = 1; i <= n; ++i){
			scanf("%d%d%d",&x,&y,&sz);
			if(sz > 4){
				for(int d = 0; d < 4; ++d)
					addsd(x,y,d);
				ans[i].first = 0;
				ans[i].second = 0;
			}
			else{
				dp[i].first = x, dp[i].second = y;
				vis[x][y] = i;
				ans[i].first = 1;
				ans[i].second = sz;
			}
		}
		scanf("%d%d",&x,&y);
		for(int d = 0; d < 4; ++d)
			addsd(x,y,d);
		for(int t = 1; t <= T; ++t){
			for(int fs = 0; fs < sdn; ++fs){
				if(bq[fs]) continue;
				sd tp = q[fs];
				if(tp.x + dir[tp.d][0] <= r && tp.x + dir[tp.d][0] > 0 && tp.y + dir[tp.d][1] <= c && tp.y + dir[tp.d][1] > 0){
					tp.x += dir[tp.d][0], tp.y += dir[tp.d][1];
					q[fs] = tp;
					if(vis[tp.x][tp.y] && ans[vis[tp.x][tp.y]].first){
						++ans[vis[tp.x][tp.y]].second;
						bq[fs] = 1;
					}
				}
				else bq[fs] = 1;
			}
			for(int i = 1; i <= n; ++i){
				if(ans[i].first && ans[i].second > 4){
					for(int d = 0; d < 4; ++d){
						addsd(dp[i].first,dp[i].second,d);
					}
					ans[i].first = 0;
					ans[i].second = t;
				}
			}
		}
		for(int i = 1; i <= n; ++i){
			printf("%d %d\n",ans[i].first,ans[i].second);
		}
	}
    return 0;
}

