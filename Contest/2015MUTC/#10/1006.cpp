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
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 2015;
const int maxn = 1e5 + 3;
//const int maxm = maxn * maxn;

//(2*N)^3log(M) 733ms
//(A, E) -> (A^n, A^(n-1)+...+E)
//(0, E) -> (0  , E            )

//(N+1)^3log(M) 78ms
//(A, 1) -> (A^n, sum(A^(N-1)+..+E))
//(0, 1) -> (0  , 1                )

struct mat{
	int n, v[51][51];
	mat(int nn):n(nn){
		memset(v, 0, sizeof(v));
	}
	mat mul(mat b){
		mat c(n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j){
				for(int k = 0; k < n; ++k){
					c.v[i][j] += v[i][k] * b.v[k][j];
				}
				c.v[i][j] %= mod;
			}
		return c;
	}
	mat emat(){
		mat x(n);
		for(int i = 0; i < n; ++i)
			x.v[i][i] = 1;
		return x;
	}
	mat pmod(int m){
		mat ans = emat(), tmp(n);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				tmp.v[i][j] = v[i][j];
		while(m > 0){
			if(m & 1) ans = ans.mul(tmp);
			tmp = tmp.mul(tmp);
			m >>= 1;
		}
		return ans;
	}
};

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n, m; scanf("%d%d", &n, &m);
		mat a(n+1);
		for(int i = 0; i < n; ++i){
			int k; scanf("%d", &k);
			for(int j = 0; j < k; ++j){
				int x; scanf("%d", &x);
				a.v[i][x-1] = 1;
			}
		}
		for(int i = 0; i < n + 1; ++i)
			a.v[n][i] = 1;
		a = a.pmod(m-1);
		int ans = 0;
		for(int i = 0; i < n + 1; ++i)
			for(int j = 0; j < n + 1; ++j){
				ans += a.v[i][j];
			}
		printf("%d\n", ans%mod);
	}
    return 0;
}

