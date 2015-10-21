#include <bits/stdc++.h>

using namespace std;

const int maxn = 8000 + 3;

struct TwoSAT{
	int n;
	vector<int> G[maxn<<1];
	bool mark[maxn<<1];
	int S[maxn<<1], c;

	bool dfs(int x){
		if(mark[x^1]) return false;
		if(mark[x]) return true;
		mark[x] = true;
		S[c++] = x;
		for(int i = 0; i < G[x].size(); ++i)
			if(!dfs(G[x][i])) return false;
		return true;
	}

	void init(int n){
		this->n = n;
		for(int i = 0; i < n * 2; ++i) G[i].clear();
		memset(mark, 0, sizeof(mark));
	}

	bool solve(){
		for(int i = 0; i < n * 2; i += 2){
			if(!mark[i] && !mark[i+1]){
				c = 0;
				if(!dfs(i)){
					while(c > 0) mark[S[--c]] = false;
					if(!dfs(i+1)) return false;
				}
			}
		}
		return true;
	}

	void add(int u, int v){
		G[u^1].push_back(v);
		G[v^1].push_back(u);
	}
}solver;

int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) && n){
		solver.init(n);
		for(int i = 0; i < m; ++i){
			int u, v; char us, vs;
			scanf("%d%c%d%c", &u, &us, &v, &vs);
			u = u << 1; v = v << 1;
			if(us == 'h') ++u;
			if(vs == 'h') ++v;
			//SPECIAL: bride
			if(u == 0 || v == 0) continue;
			solver.add(u, v);
		}
		solver.G[1].push_back(0);
		if(!solver.solve()) puts("bad luck");
		else{
			for(int i = 1; i < n; ++i){
				printf("%d%c%c", i, solver.mark[i<<1]?'w':'h', i==n-1?'\n':' ');
			}
		}
	}
	return 0;
}

