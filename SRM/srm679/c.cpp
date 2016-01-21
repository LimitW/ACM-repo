#include <bits/stdc++.h>

using namespace std;

int d[102][102];
int tmp[102], from[102], to[102];
int s, t;

struct edge{
	int v, nxt, w;
}E[4010];

int head[102], e;

void addedge(int u, int v, int w){
	E[e].v = v, E[e].w = w;
	E[e].nxt = head[u], head[u] = e++;
}

int dfs(int x, int v){
	if(v + d[x][t] > d[s][t]) return 0;
	if(tmp[x] != -1) return tmp[x];
	tmp[x] = 0;
	for(int i = head[x]; ~i; i = E[i].nxt){
		tmp[x] += dfs(E[i].v, v + E[i].w);
	}
	return tmp[x];
}

class ForbiddenStreets{
public:
vector <int> find(int N, vector <int> A, vector <int> B, vector <int> time){
	memset(d, 0x3f, sizeof(d));
	memset(head, -1, sizeof(head));
	e = 0;
	for(int i = 0; i < A.size(); ++i){
		d[A[i]][B[i]] = d[B[i]][A[i]] = time[i];
		addedge(A[i], B[i], time[i]);
		addedge(B[i], A[i], time[i]);
	}
	for(int i = 0; i < N; ++i)
		d[i][i] = 0;
	for(int k = 0; k < N; ++k)
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
	vector<int> res;
	res.clear();
	for(int i = 0; i < A.size(); ++i)
		res.push_back(0);
	for(int i = 0; i < N; ++i)
		for(int j = i + 1; j < N; ++j){
			s = i, t = j;
			memset(tmp, -1, sizeof(tmp));
			tmp[j] = 1;
			dfs(i, 0);
			for(int it = 0; it < N; ++it)
				from[it] = tmp[it];
			s = j, t = i;
			memset(tmp, -1, sizeof(tmp));
			tmp[i] = 1;
			dfs(j, 0);
			for(int it = 0; it < N; ++it)
				to[it] = tmp[it];
			for(int it = 0; it < A.size(); ++it){
				int x = A[it], y = B[it];
				if(d[i][x] > d[i][y]) swap(x, y);
				if(d[i][x] + time[it] + d[y][j] == d[i][j] && (long long)(to[x] * from[y]) == from[i])
					++res[it];
			}
		}
	return res;
}
};
