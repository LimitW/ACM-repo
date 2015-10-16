#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

struct rec{
	int x1, y1, x2, y2, v;
	long long w;
	rec(int a = -1, int b = -1, int c = -1, int d = -1, int e = INF)
	:x1(a), y1(b), x2(c), y2(d), v(e){
		w = 1ll * (c - a) * (d - b);
	}
	bool operator < (rec b) const{
		return x1 < b.x1 || (x1 == b.x1 && y1 < b.y1);
	}
}s[11], g[25][25];

int mask[25][25];

bool inter(rec a, rec b){
	return a.x1 >= b.x1 && a.y1 >= b.y1 && a.x2 <= b.x2 && a.y2 <= b.y2;
}

int X[21], Y[21];

long long dp[2][1025], v1[25][25], v2[25][25];

long long pmod(long long a, long long b){
	long long ans = 1, tmp = a;
	while(b > 0){
		if(b & 1) ans = ans * tmp % mod;
		tmp = tmp * tmp % mod;
		b >>= 1;
	}
	return ans;
}

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		memset(dp, 0, sizeof(dp));
		memset(mask, 0, sizeof(mask));
		int h, w, m, n;
		scanf("%d%d%d%d", &h, &w, &m, &n);
		int a = 0, b = 0;
		X[a++] = 1, X[a++] = w + 1;
		Y[b++] = 1, Y[b++] = h + 1;
		for(int i = 0; i < n; ++i){
			scanf("%d%d%d%d%d", &s[i].x1, &s[i].y1, &s[i].x2, &s[i].y2, &s[i].v);
			++s[i].x2, ++s[i].y2;
			X[a++] = s[i].x1, X[a++] = s[i].x2;
			Y[b++] = s[i].y1, Y[b++] = s[i].y2;
		}
		sort(X, X + a);
		sort(Y, Y + b);
		a = unique(X, X + a) - X;
		b = unique(Y, Y + b) - Y;
		for(int i = 0; i < a - 1; ++i)
			for(int j = 0; j < b - 1; ++j){
				g[i][j] = rec(X[i], Y[j], X[i+1], Y[j+1]);
				for(int k = 0; k < n; ++k){
					if(inter(g[i][j], s[k])){
						if(g[i][j].v < s[k].v) continue;
						else if(g[i][j].v == s[k].v)
							mask[i][j] |= 1 << k;
						else{
							g[i][j].v = s[k].v;
							mask[i][j] = 1 << k;
						}
					}
				}
			}
		for(int i = 0; i < a - 1; ++i)
			for(int j = 0; j < b - 1; ++j){
				if(g[i][j].v != INF){
					v1[i][j] = (pmod(g[i][j].v, g[i][j].w) - pmod(g[i][j].v - 1, g[i][j].w) + mod) % mod;
					v2[i][j] = pmod(g[i][j].v - 1, g[i][j].w);
				}
			}
		int mst = 1 << n;
		dp[0][0] = 1;
		int flag = 0;
		for(int i = 0; i < a - 1; ++i)
			for(int j = 0; j < b - 1; ++j){
				if(g[i][j].v == INF) continue;
				flag ^= 1;
				for(int s = mst - 1; s >= 0; --s) dp[flag][s] = 0;
				for(int s = mst - 1; s >= 0; --s){
					dp[flag][s|mask[i][j]] += (1ll * dp[flag^1][s] * v1[i][j] % mod);
					dp[flag][s|mask[i][j]] %= mod;
					dp[flag][s] += (1ll * dp[flag^1][s] * v2[i][j] % mod);
					dp[flag][s] %= mod;
				}
			}
		long long ans = dp[flag][mst-1];
		for(int i = 0; i < a - 1; ++i)
			for(int j = 0; j < b - 1; ++j){
				if(g[i][j].v == INF) ans = ans * pmod(m, g[i][j].w) % mod;
			}
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}

