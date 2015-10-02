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
const int maxn = 1e5 + 3;

vector<int> g[12];
int vis[maxn];

bool solve(int n,int m){
	if(n * (n + 1) / 2 % m != 0) return false;
	memset(vis,0,sizeof(vis));
	int pre = n, tmp =  n * (n + 1) / 2 / m;
	for(int i = 0; i < m; ++i) g[i].clear();
	for(int i = 0; i < m; ++i){
		int cnt = tmp;
		for(int j = min(cnt,n); cnt && j >= 0; --j){
			if(!vis[j]){
				cnt -= j;
				g[i].push_back(j);
				vis[j] = 1;
				j = min(cnt+1,j);
			}
		}
	}
	bool flag = 1;
	for(int i = 1; i <= n; ++i){
		if(!vis[i]) { flag = 0; break; }
	}
	return flag;
}

int main(){
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; ++kase){
		int n, m; scanf("%d%d", &n, &m);
		if(solve(n,m)){
			puts("YES");
			for(int i = 0; i < m; ++i){
				int sz = g[i].size();
				printf("%d",sz);
				for(int j = 0; j < sz; ++j)
					printf(" %d",g[i][j]);
				puts("");
			}
		}
		else puts("NO");
	}
	return 0;
}

