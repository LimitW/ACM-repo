#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> G[52];
int da[52], db[52];

class Treestrat{
public:
	int roundcnt(vector <int> tree, vector <int> A, vector <int> B){
		int n = tree.size();
		for(int i = 1; i <= n; ++i){
			G[i].push_back(tree[i-1]);
			G[tree[i-1]].push_back(i);
		}
		memset(db, -1, sizeof(db));
		queue<int> Q;
		for(int i = 0; i < B.size(); ++i){
			Q.push(B[i]);
			db[B[i]] = 0;
		}
		while(!Q.empty()){
		   int u = Q.front(); Q.pop();
		   for(int i = 0; i < G[u].size(); ++i){
		   		int v = G[u][i];
		   		if(db[v] != -1) continue;
		   		db[v] = db[u] + 1;
		   		Q.push(v);
		   }
		}
		int ans = INF;
		for(int i = 0; i < A.size(); ++i){
			 int cnt = 0;
			 memset(da, -1, sizeof(da));
			 while(!Q.empty()) Q.pop();
			 Q.push(A[i]); da[A[i]] = 0;
			 while(!Q.empty()){
			 	int u = Q.front(); Q.pop();
			 	for(int j = 0; j < G[u].size(); ++j){
			 		int v = G[u][j];
			 		if(da[v] != -1) continue;
			 		da[v] = da[u] + 1;
			 		Q.push(v);
			 	}
			 }
			 for(int j = 0; j <= n; ++j){
				 if(da[j] < db[j]) cnt = max(cnt, db[j]);
			 }
			 ans = min(ans, cnt);
		}
		return ans;
	}
};

