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

const int maxn = 1000 + 3;

int p[maxn];

int find(int u){
	return p[u] == u ? u : p[u] = find(p[u]);
}

void Union(int u,int v){
	int x = find(u) , y = find(v);
	if(x != y) p[y] = x;
}

vector<int> vv;

int main(){
	int n,m;
	while(scanf("%d",&n) && n){
        scanf("%d",&m);
		for(int i = 1; i <= n; ++i)
			p[i] = i;
		for(int i = 0; i < m; ++i){
			int u,v; scanf("%d%d",&u,&v);
			Union(u,v);
		}
        vv.clear();
		for(int i = 1; i <= n; ++i)
			vv.push_back(find(i));
		sort(vv.begin(),vv.end());
		int sz = unique(vv.begin(),vv.end()) - vv.begin();
		printf("%d\n",sz-1);
	}
	return 0;
}
