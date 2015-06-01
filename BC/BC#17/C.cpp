#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
struct edge{
	int u,v;
}e[maxn*10];

int p[maxn];

int find(int x){
	return p[x] == x ? x : p[x] = find(p[x]);
}

void Union(int u , int v){
	int x = find(u);
	int y = find(v);
	if(x != y) p[x] = y;
}

int main(){
	int T; cin >> T;
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i = 1; i <= n; i++) p[i] = i;
		for(int i = 0; i < k; i++)
		{
			int u , v;
			scanf("%d%d",&u,&v);
			e[i].u = u; e[i].v = v;
			Union(u,v);
		}
	}
	return 0;
}
