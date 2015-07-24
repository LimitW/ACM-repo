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
const int mod = 1e9 + 7;
const int maxn = 1e5 + 3;

struct edge{
	int u,v;
}e[30];

pii cnt[10];
int p[10], n, m, ans;

void dfs(int cur){
	if(cur == m){
		bool fail = 0;
		for(int i = 1; i <= n; ++i)
			if(cnt[i].first != cnt[i].second) { fail = 1; break; }
		if(!fail) ++ans;
		return;
	}
	int uu = e[cur].u, vv = e[cur].v;
	if(cnt[uu].first < p[uu] / 2 && cnt[vv].first < p[vv] / 2){
		++cnt[uu].first, ++cnt[vv].first;
		dfs(cur+1);
		--cnt[uu].first, --cnt[vv].first;
	}
	if(cnt[uu].second < p[uu] / 2 && cnt[vv].second < p[vv] / 2){
		++cnt[uu].second, ++cnt[vv].second;
		dfs(cur+1);
		--cnt[uu].second, --cnt[vv].second;
	}
}

int main(){
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; ++kase){
		memset(cnt,0,sizeof(cnt));
		memset(p,0,sizeof(p));
		scanf("%d%d",&n,&m);
		for(int i = 0; i < m; ++i){
			scanf("%d%d",&e[i].u,&e[i].v);
			++p[e[i].u], ++p[e[i].v];
		}
		bool flag = m & 1;
		for(int i = 1; i <= n; ++i){
			if(p[i] & 1) {
				flag = 1; break;
			}
		}
		if(flag) { puts("0"); continue; }
		ans = 0;
		dfs(0);
		printf("%d\n",ans);
	}
    return 0;
}
