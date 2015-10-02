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
const double pi = acos(-1.0);
const long double eps = 1e-9;

int vis[7][2100000];

struct node{
	int v, hsv;
	node(int v = 0, int hsv = 0):v(v), hsv(hsv){};
};

int top[7];
queue<node> Q;

void bfs(int n){
	node x;
	for(int i = 0; i < n; ++i){
		x.hsv += i << 3 * i;
		top[i] = i;
	}
	vis[n-1][x.hsv] = 0;
	Q.push(x);
	while(!Q.empty()){
		node u = Q.front();
		Q.pop();
		memset(top, -1, sizeof(top));
		for(int i = n - 1; i >= 0; --i){
			top[(u.hsv >> 3 * i) & 7] = i;
		}
		for(int i = 0; i < n; ++i){
			if(top[i] == -1) continue;
			if(i > 0 && (top[i] < top[i-1] || top[i-1] == -1)){
				node v = node(u.v + 1);
				v.hsv = u.hsv - (1 << 3*top[i]);
				if(vis[n-1][v.hsv] == -1){
					vis[n-1][v.hsv] = v.v;
					Q.push(v);
				}
			}
			if(i < n - 1 && (top[i] < top[i+1] || top[i+1] == -1)){
				node v = node(u.v + 1);
				v.hsv = u.hsv + (1 << 3*top[i]);
				if(vis[n-1][v.hsv] == -1){
					vis[n-1][v.hsv] = v.v;
					Q.push(v);
				}
			}
		}
	}
}

int main(){
	memset(vis, -1, sizeof(vis));
	for(int i = 1; i <= 7; ++i) bfs(i);
	int T; scanf("%d", &T);
	map<int, int> mp;
	while(T--){
		mp.clear();
		int n; scanf("%d", &n);
		node x;
		for(int i = 0; i < n; ++i){
			int v; scanf("%d", &v);
			mp[v] = i;
		}
		map<int, int>::iterator it = mp.begin();
		int st = 0;
		for(int i = 0; it != mp.end(); ++i, ++it){
			st += it->second << 3 * i;
		}
		printf("%d\n", vis[n-1][st]);
	}
    return 0;
}

