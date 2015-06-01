/************************************************
 * Title :
 * Author : LimitW
 * Date : 2014.10.26.
 * Source : BestCoder #14 B
 * Note : dp / dfs
*************************************************/

/*dfs 734ms*/

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

#define LL long long
#define pii pair<int,int>

vector<pii> v;
pii o = make_pair(1,1);
bool vis[52][52];
int ans[12];
int init[12];

int dist(pii a, pii b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}


void dfs(int x,int n,int i,int tmp,int cur)
{
    vis[v[i].first][v[i].second] = 1;
    if(cur == n) {
        ans[x] = min(ans[x],tmp+dist(v[i],o));
        vis[v[i].first][v[i].second] = 0;
        return;
    }
    for(int to = 0; to < n; to++)
    {
        if(vis[v[to].first][v[to].second] || to == i) continue;
        if(tmp < ans[x]) { dfs(x,n,to,tmp+dist(v[to],v[i]),cur+1); vis[v[to].first][v[to].second] = 0; }
    }
    return;
}

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        v.clear();
        for(int i = 1; i <= n; i++)
             for(int j = 1 ; j <= m; j++){
                int t; scanf("%d",&t);
	   if( t != 0 && !(i == 1 && j == 1) ){ v.push_back(make_pair(i,j)); }
	}
        int N = v.size();
        if(N == 0){ printf("0\n"); continue;}
        for(int i = 0; i < N; i++)
        { init[i] = dist(v[i],o); ans[i] = INF; }
        int ans2 = INF;
        for(int i = 0; i < N; i++)
        {
            memset(vis,0,sizeof(vis));
            dfs(i,N,i,init[i],1);
            ans2 = min(ans2,ans[i]);
        }
        printf("%d\n",ans2);
    }
    return 0;
}
