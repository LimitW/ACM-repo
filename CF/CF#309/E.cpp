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

const int maxn = 1e5 + 3;

const int mod = 1e9 + 7;

vector<pair<int,int> > e[maxn];

int vis[maxn];

bool dfs(int u){
    int sz = e[u].size();
    bool ok = 1;
    for(int i = 0; i < sz; ++i){
        int v = e[u][i].first , c = e[u][i].second;
        if(!vis[v]){
            vis[v] = c ? vis[u] : -vis[u];
            ok = dfs(v);
        }
        if(c && vis[v] != vis[u]) return 0;
        if(!c && vis[v] != -vis[u]) return 0;
    }
    return ok;
}

int main(){
    int n,m; scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        --u,--v;
        e[u].push_back(make_pair(v,c));
        e[v].push_back(make_pair(u,c));
    }
    memset(vis,0,sizeof(vis));
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            vis[i] = 1; ++cnt;
            if(!dfs(i)){ cnt = 0; break; }
        }
    }
    LL ans = cnt ? 1 : 0;
    for(int i = 1; i < cnt; ++i){
        ans *= 2;
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}

