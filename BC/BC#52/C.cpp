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
const int maxn = 50005;
//const int maxm = maxn * maxn;

LL n, m;
LL h[maxn], a[maxn], sum[maxn];

LL gcd(LL a, LL b){
	return b == 0 ? a : gcd(b , a%b);
}

LL cn3(LL x){
	return x * (x - 1) * (x - 2) / 6;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		memset(h, 0, sizeof(h));
		scanf("%I64d%I64d", &n, &m);
		for(int i = 0; i < n; ++i){
			scanf("%I64d",&a[i]);
		}
		for(int i = 0; i < m; ++i){
			int l, r; scanf("%d%d", &l, &r);
			++h[l]; --h[r+1];
		}
		sum[0] = 0;
		for(int i = 1; i <= n; ++i){
			sum[i] = sum[i-1] + h[i];
		}
		LL p = 0;
		for(int i = 1; i <= n; ++i){
			p += a[i-1] * cn3(sum[i]);
		}
		LL q = cn3(m);
		if(p == 0 || q == 0) puts("0");
		else {
			LL x = gcd(p,q);
			p /= x, q /= x;
			if(q == 1) printf("%I64d\n",p);
			else printf("%I64d/%I64d\n", p, q);
		}
	}
    return 0;
}

