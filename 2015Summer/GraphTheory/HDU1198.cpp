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
// 0u 1d 2l 3r
vector<int> mp[12];
void init(){
	for (int i = 0; i < 4; ++i){
		if (i == 0){
			mp[0].push_back(i);
			mp[1].push_back(i);
			mp[4].push_back(i);
			mp[6].push_back(i);
			mp[7].push_back(i);
			mp[9].push_back(i);
			mp[10].push_back(i);
		}
		else if (i == 1){
			mp[2].push_back(i);
			mp[3].push_back(i);
			mp[4].push_back(i);
			mp[7].push_back(i);
			mp[8].push_back(i);
			mp[9].push_back(i);
			mp[10].push_back(i);
		}
		else if (i == 2){
			mp[2].push_back(i);
			mp[0].push_back(i);
			mp[5].push_back(i);
			mp[6].push_back(i);
			mp[7].push_back(i);
			mp[8].push_back(i);
			mp[10].push_back(i);
		}
		else {
			mp[1].push_back(i);
			mp[3].push_back(i);
			mp[5].push_back(i);
			mp[6].push_back(i);
			mp[8].push_back(i);
			mp[9].push_back(i);
			mp[10].push_back(i);
		}
	}
}

int g[52][52];
int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
vector<int> G[2510];
int p[2510];

int Find(int u){
	return p[u] == u ? u : p[u] = Find(p[u]);
}

void Union(int x, int y){
	int u = Find(x), v = Find(y);
	if (u != v) p[v] = u;
}

int main(){
	init();
	int n, m;
	while (cin >> n >> m && n != -1){
		string ss;
		for (int i = 0; i < n; ++i){
			cin >> ss;
			for (int j = 0; j < m; ++j){
				g[i][j] = ss[j] - 'A';
			}
		}
		int sz;
		for (int i = 0; i < 2510; ++i) G[i].clear();
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j){
			sz = mp[g[i][j]].size();
			for (int z = 0; z < sz; ++z){
				int o = mp[g[i][j]][z];
				if (o == 0 || o == 2) continue;
				int dx = i + dir[o][0], dy = j + dir[o][1];
				if (dx >= 0 && dx < n && dy >= 0 && dy < m){
					int sz2 = mp[g[dx][dy]].size();
					for (int k = 0; k < sz2; ++k){
						int o2 = mp[g[dx][dy]][k];
						if (o2 == 5 - o || o2 == 1 - o){
							int u = dx * m + dy, v = i * m + j;
							G[u].push_back(v);
							G[v].push_back(u);
							break;
						}
					}
				}
			}
			}
		int nn = n * m;
		for (int i = 0; i < nn; ++i) p[i] = i;
		for (int i = 0; i < nn; ++i){
			sz = G[i].size();
			for (int j = 0; j < sz; ++j)
				Union(i, G[i][j]);
		}
		vector<int> ans;
		ans.clear();
		for (int i = 0; i < nn; ++i){
			ans.push_back(Find(i));
		}
		sort(ans.begin(), ans.end());
		sz = unique(ans.begin(), ans.end()) - ans.begin();
		printf("%d\n", sz);
	}
	return 0;
}
