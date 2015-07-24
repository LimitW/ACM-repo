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
const int mod = 1e9 + 7;
const int maxn = 1e5 + 3;

int a[maxn];
int q[maxn][20] , q2[maxn][20];
int pow2[20];

void RMQ(int n){
	for(int j = 0; pow2[j] <= n; j++)
		for(int i = 1; i <= n; i++){
			if(j == 0){
				q[i][j] = a[i];
				q2[i][j] = a[i];
			}
			else if(i + pow2[j] - 1 <= n){
				q[i][j] = min( q[i][j-1] , q[i+pow2[j-1]][j-1] );
				q2[i][j] = max( q2[i][j-1] , q2[i+pow2[j-1]][j-1] );
			}
			else break;
		}
}

int query(int l,int r,int op){
	if(l == r) return a[l];
	else {
		int e = log2((double)(r-l+1));
		if(op) return min(q[l][e],q[r-pow2[e]+1][e]);
		else return max(q2[l][e],q2[r-pow2[e]+1][e]);
	}
}

int main(){
	pow2[0] =1;
	for(int i = 1; i < 20; i++) pow2[i] = pow2[i-1] * 2;
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; ++kase){
		int n,k; scanf("%d%d",&n,&k);
		for(int i = 1; i <= n; ++i)
			scanf("%d",&a[i]);
		RMQ(n);
		LL ans = 0;
		for(int i = 1; i <= n; ++i){
			int ll = i, rr = n , ok = i;
			while(ll < rr){
				int md = (ll + rr) >> 1;
				if(query(i,md,0) - query(i,md,1) < k){
					ll = md + 1;
					ok = md;
				}
				else rr = md - 1;
			}
			if(ok != n && (query(i,ok+1,0) - query(i,ok+1,1) < k)) ++ok;
			ans += (LL)(ok-i+1);
		}
		printf("%I64d\n",ans);
	}
    return 0;
}
