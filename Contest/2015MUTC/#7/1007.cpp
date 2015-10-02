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
const int maxn = 2e5 + 3;
//const int maxm = maxn * maxn;

int a[maxn], vis[maxn];
char s[maxn];

int q[maxn][20];
int pow2[20];

void RMQ(int n){
	pow2[0] = 1;
	for(int i = 1; i < 20; i++) pow2[i] = pow2[i-1] * 2;
	for(int j = 0; pow2[j] <= n; j++)
		for(int i = 1; i <= n; i++){
			if(j == 0){
				q[i][j] = a[i];
			}
			else if(i + pow2[j] - 1 <= n){
				q[i][j] = min( q[i][j-1] , q[i+pow2[j-1]][j-1] );
			}
			else break;
		}
}

int query(int l,int r){
	if(l == r) return a[l];
	else {
		int e = log2((double)(r-l+1));
		return min(q[l][e],q[r-pow2[e]+1][e]);
	}
}

vector<pii> x;

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		x.clear();
		scanf("%s", s);
		int n = strlen(s);
		for(int i = 0; i < n; ++i){
			if(s[i] == '?') vis[i+1] = -1;
			else vis[i+1] = s[i] - '0';
		}
		vis[n+1] = 0;
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
			if(vis[i] != -1 && vis[i] == vis[i-1]) continue;
			ans += a[i];
		}
		RMQ(n);
		for(int i = 1, j = i + 1; i <= n; ){
			if(vis[i] == -1){
				for(j = i + 1; j < n + 1; ++j)
					if(vis[j] != -1) break;
				x.push_back(make_pair(i,j-1));
				i = j;
			}
			else ++i;
		}
		int sz = x.size();
		for(int i = 0; i < sz; ++i){
			int l = x[i].first, r = x[i].second, len = r - l + 1;
			if(vis[l-1] ^ vis[r+1]){
				if(len & 1) ans -= query(l,r+1);
			}
			else{
				if(!(len & 1)) ans -= query(l,r+1);
			}
		}
		printf("Case #%d: %d\n",kase,ans);
	}
    return 0;
}

