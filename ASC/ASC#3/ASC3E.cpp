//============================================================================
// Name        : E.cpp
// Author      : LimitW
// Date        : 2014.11.3
// Version     :
// Copyright   : ASC #3 E
// Description : SPFA , Graph
//============================================================================

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
const int maxn = 502;

int u[maxn*maxn] , v[maxn*maxn];
int first[maxn] , next[maxn*maxn];
int dist[maxn];
bool vis[maxn] , mp[maxn][maxn];
int n,m,s,t;
vector<int> ans[maxn];

void bfs(){
    priority_queue<pii , vector<pii> , greater<pii> > pq;
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    pq.push(make_pair(dist[s],s));
    while(!pq.empty()) {
        pii u = pq.top(); pq.pop();
        if(vis[u.second]) continue;
        vis[u.second] = 1;
        for(int e = first[u.second]; e != -1; e = next[e])
        {
            if(vis[v[e]]) continue;
            if(dist[v[e]] > dist[u.second] + 1)
            {
                dist[v[e]] =dist[u.second] + 1;
                if(!vis[v[e]]) {
                    pq.push(make_pair(dist[v[e]],v[e]));
                }
            }
        }
    }
    return;
}

int main(){
        memset(first,-1,sizeof(first));
        scanf("%d %d %d %d",&n,&m,&s,&t);
        for(int i = 1; i <= m; i++) {
            int a, b;  scanf("%d %d",&a,&b);
            u[i] = a; v[i] = b;
            u[i+m] = b; v[i+m] = a;
            next[i+m] = first[b]; first[b] = i+m;
            next[i] = first[a]; first[a] = i;
        }
        bfs();
        printf("%d\n",dist[t]);
        for(int i = 0; i < n; i++) ans[i].clear();
        for(int i = 1; i <= m; i++)
        {
            if(dist[v[i]] == dist[u[i]] + 1)
                ans[ dist[u[i]] ].push_back(i);
            else
                ans[ dist[v[i]] ].push_back(i);
        }
        for(int i = 0; i < dist[t]; i++){
            printf("%d",ans[i].size());
            for(int j = 0; j < ans[i].size(); j++){
                printf(" %d",ans[i][j]);
            }
            printf("\n");
        }
    return 0;
}


/* RE directed graph
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
const int maxn = 502;

int u[maxn*maxn] , v[maxn*maxn];
int first[maxn] , next[maxn*maxn];
int dist[maxn];
bool vis[maxn];
int n,m,s,t;
vector<int> ans[maxn];
priority_queue<pii , vector<pii> , greater<pii> > pq;

void bfs(){
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    pq.push(make_pair(dist[s],s));
    while(!pq.empty()) {
        pii u = pq.top(); pq.pop();
        if(vis[u.second]) continue;
        vis[u.second] = 1;
        for(int e = first[u.second]; e != -1; e = next[e])
        {
            if(vis[v[e]]) continue;
            if(dist[v[e]] > dist[u.second] + 1)
            {
                dist[v[e]] =dist[u.second] + 1;
                if(!vis[v[e]]) {
                    pq.push(make_pair(dist[v[e]],v[e]));
                }
            }
        }
    }
    return;
}

int main(){
        memset(first,-1,sizeof(first));
        scanf("%d %d %d %d",&n,&m,&s,&t);
        for(int i = 1; i <= m; i++) {
            int a, b;  scanf("%d %d",&a,&b);
            u[i] = a; v[i] = b;
            next[i] = first[a]; first[a] = i;
        }
        bfs();
        printf("%d\n",dist[t]);
        for(int i = 1; i <= n; i++){
            cout << dist[i] << endl;
        }
        for(int i = 0; i < n; i++) ans[i].clear();
        for(int i = 1; i <= m; i++)
        {
            if(dist[v[i]] == dist[u[i]] + 1)
                ans[ dist[u[i]] ].push_back(i);
            else
                ans[ dist[v[i]] ].push_back(i);
        }
        for(int i = 0; i < dist[t]; i++){
            printf("%d",ans[i].size());
            for(int j = 0; j < ans[i].size(); j++){
                printf(" %d",ans[i][j]);
            }
            printf("\n");
        }
    return 0;
}*/
