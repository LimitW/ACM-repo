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
const int mod = 1e9 + 7;
const int maxn = 100 + 4;
//const int maxm = maxn * maxn;

int a[maxn][maxn];
LL fac[maxn];
int vis[maxn];

int main(){
	fac[1] = 1LL;
	for(int i = 2; i < maxn; ++i){
		fac[i] = fac[i-1] * (LL)i;
		fac[i] %= mod;
	}
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		int cnt = 0;
		LL ans = 1;
		for(int i = 1; i <= m; ++i){
			memset(vis, 0, sizeof(vis));
			scanf("%d", &a[i][1]);
			if(a[i][1] != -1){
				vis[a[i][1]] = 1;
				for(int j = 2; j <= n; ++j){
					scanf("%d", &a[i][j]);
					if(vis[a[i][j]]) ans = 0;
					vis[a[i][j]] = 1;
				}
			}
			else ++cnt;
		}
		if(!cnt){
			for(int i = 1; i <= n; ++i){
				int nxt = i;
				for(int j = m; j > 0; --j)
					nxt = a[j][nxt];
				if(nxt != i){
					ans = 0; break;
				}
			}
		}
		while(cnt > 1){
			ans *= fac[n];
			ans %= mod;
			--cnt;
		}
		cout << ans << '\n';
	}
    return 0;
}

