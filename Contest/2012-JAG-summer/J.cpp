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
const int maxn = 1e6 + 3;

struct edge{
	int v, nxt;
}E[maxn];

int n, e;
int head[maxn], w[maxn], sz[maxn];

void addedge(int u, int v){
	E[e].v = v;
	E[e].nxt = head[u];
	head[u] = e++;
}

vector<int> r;

LL ans;
int Q[maxn], Head, Tail;
priority_queue<int, vector<int>, greater<int> > pq;

void bfs(int s){
	Head = 0, Tail = 0;
	Q[Tail++] = s;
	while(Head < Tail){
		int i = Q[Head++];
		sz[i] = w[i];
		for(int j = head[i]; ~j; j = E[j].nxt){
			Q[Tail++] = E[j].v;
		}
	}
	for(int i = Tail - 1; i >= 0; --i){
		for(int j = head[Q[i]]; ~j; j = E[j].nxt){
			sz[Q[i]] += sz[E[j].v];
			pq.push(sz[E[j].v]);
		}
		while(!pq.empty()){
			int cnt = pq.top(); pq.pop();
			ans += 1ll * cnt * pq.size();
		}
	}
}

int main(){
	while(~scanf("%d", &n)){
		e = 0; r.clear();
		memset(head, -1, sizeof(head));
		for(int i = 0; i < n; ++i){
			int v; scanf("%d%d", &w[i], &v);
			if(v != -1) addedge(v, i);
			else r.push_back(i);
		}
		ans = 0;
		for(int i = 0; i < r.size(); ++i) bfs(r[i]);
		printf("%lld\n", ans);
	}
	return 0;
}


