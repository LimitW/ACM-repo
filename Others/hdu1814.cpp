#include <bits/stdc++.h>

using namespace std;

const int maxn = 80 + 3;

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
		G[u].push_back(v^1);
		G[v].push_back(u^1);
	}

}solver;

int main(){
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		solver.init(n);
		for(int i = 0; i < m; ++i){
			int u, v; scanf("%d%d", &u, &v);
			solver.add(u - 1, v - 1);
		}
		if(!solver.solve()) puts("NIE");
		else{
			for(int i = 0; i < n * 2; i += 2){
				printf("%d\n", solver.mark[i] ? i+1 : i+2);
			}
		}
	}
	return 0;
}

