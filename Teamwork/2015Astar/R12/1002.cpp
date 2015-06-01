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

struct edge{
	int u,v;
	short w;
	bool operator < (edge b) const {
		return w < b.w;
	}
}eg[1001*1001*2];

int p[1001*1001];
short val[1001*1001];

int find(int u){
    return p[u] == u ? u : p[u] = find(p[u]);
}

int n,m,e;

void addedge(int uu , int vv , int ww){
    eg[e].u = uu; eg[e].v = vv; eg[e].w = ww; e++;
}

int Kruskal(){
    for(int i = 0; i < n * m; ++i) p[i] = i;
    int ans = 0;
    for(int ee = 0; ee < e; ++ee){
        int x = find(eg[ee].u) , y = find(eg[ee].v);
        if(x != y) {
        	ans += eg[ee].w; p[x] = y;
        }
    }
    return ans;
}

int main(){
    int T; scanf("%d",&T);
    for(int kase = 1; kase <= T; ++kase){
        printf("Case #%d:\n",kase);
        scanf("%d%d",&n,&m);
        e = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                scanf("%d",&val[i * m + j]);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(i + 1 < n && i + 1 >= 0){
                    addedge((i+1)*m+j , i*m+j , abs(val[(i+1)*m+j] - val[i*m+j]));
                }
                if(j + 1 >= 0 && j + 1 < m){
                	addedge( i*m+j+1 , i*m+j , abs(val[i*m+j+1] - val[i*m+j]));
                }
            }
        }
        sort(eg,eg+e);
        int ans = Kruskal();
        printf("%d\n",ans);
    }
    return 0;
}

