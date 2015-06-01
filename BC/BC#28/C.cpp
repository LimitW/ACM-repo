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

#define pii pair<long long,int>
#define piii pair<pii,long long>

const long long INF = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;

struct edge{
	int u,v;
	long long w;
	bool operator < (const edge b) const {
		return w < b.w;
	}
}e[maxm];

long long ans[maxn] , dp[maxm];
int n,m;
long long k;

int main(){
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; kase++){
        scanf("%d%d%I64d",&n,&m,&k);
        for(int i = 0; i < m; i++) {
        	scanf("%d%d%I64d",&e[i].u,&e[i].v,&e[i].w);
        }
        sort(e,e+m);
        for(int i = 1; i <= n; i++) ans[i] = INF;
        //for(int i = 0; i < m; i++) dp[i] = INF;
        ans[1] = 0; int j = 0;
        for(int i = 0; i < m; ++i)
        {
        	while(j < m && e[j].w + k <= e[i].w)
        	{
        		ans[ e[j].v ] = min(ans[e[j].v] , dp[j]);
        		++j;
        	}
        	if(ans[e[i].u] == INF) dp[i] = INF;
        	else dp[i] = ans[e[i].u] + e[i].w;
        }
        while( j < m )
        {
        	ans[e[j].v] = min(dp[j],ans[e[j].v]);
        	++j;
        }
        if(ans[n] >= INF) printf("-1\n");
        else printf("%I64d\n",ans[n]);
	}
    return 0;
}
