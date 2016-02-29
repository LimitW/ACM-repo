#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

long long a[maxn];

long long f[maxn][2];

const int mod = 1e9 + 7;

vector<int> G[maxn];

long long dfs(int cur, int fa){
	f[cur][0] = 1;
	for(int i = 0; i < G[cur].size(); ++i){
		if(G[cur][i] == fa) continue;
		f[cur][0] = (1ll * f[cur][0] * (dfs(G[cur][i], cur) + 1)) % mod;
	}
	return f[cur][0];
}

long long qpow(long long a, long long b){
	long long res = 1;
	while(b > 0){
		if(b & 1) res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

long long rev(long long a){
	return qpow(a, mod - 2);
}

void dfs2(int cur, int fa){
	long long tot = 1;
	for(int i = 0; i < G[cur].size(); ++i){
		if(G[cur][i] == fa) continue;
		dfs2(G[cur][i], cur);
		tot = tot * (f[G[cur][i]][0]+1) % mod;
	}
	f[cur][1] = f[cur][0];
	for(int i = 0; i < G[cur].size(); ++i){
		if(G[cur][i] == fa) continue;
		f[cur][1] = (f[cur][1] + ( (tot * rev(f[G[cur][i]][0] + 1) % mod) * f[G[cur][i]][1] % mod  ) ) % mod;
	}
}

class SubtreesCounting {
public:
int sumOfSizes(int n, int a0, int b, int c, int m){
	memset(f, 0, sizeof(f));
	for(int i = 0; i < n; ++i)
		G[i].clear();
	a[0] = a0;
	for(int i = 1; i < n - 1; ++i)
    	a[i] = (b * a[i-1] + c) % m;
	for(int i = 1; i < n; ++i){
    	int j = a[i-1] % i;
    	G[i].push_back(j);
    	G[j].push_back(i);
    }
    dfs(0, -1);
    dfs2(0, -1);
    long long x = 0;
    for(int i = 0; i < n; ++i)
    	x = (x + f[i][1]) % mod;
    return x;
}
};

