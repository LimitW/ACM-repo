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
const int maxn = 1e4 + 3;
const int maxm = 2e5 + 3;

int n, m, k, t;
int u[maxm], v[maxm], nxt[maxm], w[maxm];
int head[maxn], vis[maxn];
int e;

void addedge(int uu, int vv, int ww){
	u[e] = uu, v[e] = vv, w[e] = ww;
	nxt[e] = head[uu], head[uu] = e++;
}

struct node{
	int f, v;
	node(int ff = -1, int vv = -1): f(ff), v(vv){};
};

bool bfs(int r, int q){
	queue<node> Q;
	Q.push(node(1,0));
	vis[1] = 1;
	while(!Q.empty()){
		node x = Q.front();
		Q.pop();
		if(x.f == t){
			if(x.v <= q) return 1;
			continue;
		}
		if(x.v > k) break;
		if(x.v == k) continue;
		for(int i = head[x.f]; i != -1; i = nxt[i]){
			int to = v[i];
			if(w[i] > q || vis[to]) continue;
			vis[to] = 1;
			Q.push(node(to,x.v+1));
		}
	}
	return 0;
}

int main(){
	while(~scanf("%d%d%d%d", &n, &m, &k, &t)){
		memset(head, -1, sizeof(head));
		e = 0;
		int l = 1, r = 1e6;
		for(int i = 0; i < m; ++i){
			int uu, vv, ww;
			scanf("%d%d%d", &uu, &vv, &ww);
			addedge(uu, vv, ww);
			addedge(vv, uu, ww);
			r = max(ww, r);
			l = min(l, ww);
		}
		int ans = r;
		while(l <= r){
			memset(vis, 0, sizeof(vis));
			int mid = l + r >> 1;
			if(bfs(1, mid)){
				ans = min(ans, mid);
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
    return 0;
}

