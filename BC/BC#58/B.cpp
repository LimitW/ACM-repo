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
const int maxn = 1e5 + 3;
const int mod = 1e9 + 7;

int a[maxn], f[maxn];

map<int, int> mp;

long long quickpow(long long m,long long n){
	if(n < 0) return 0;
	long long ans = 1;
	while(n){
		if(n&1) ans = ans * m % mod;
		n >>= 1;
		m = m * m % mod;
	}
	return ans;
}

int main(){
	int T; scanf("%d", &T);
	for(int kase = 0; kase < T; ++kase){
		int n; scanf("%d", &n);
		LL sum = 0;
		mp.clear();
		for(int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
			if(mp.find(a[i]) != mp.end()){
				int j = mp[a[i]];
				f[i] = f[j] + quickpow(2, j - 1);
				f[i] %= mod;
			}
			else f[i] = 0;
			mp[a[i]] = i;
			sum += 1ll * a[i];
		}
		sum %= mod;
		LL ans = sum * quickpow(2, n - 1) % mod;
		for(int i = 1; i <= n; ++i){
			ans -= 1ll * a[i] * f[i] % mod * quickpow(2, n - i) % mod;
			while(ans < 0) ans += mod;
		}
		cout << ans << '\n';
	}
	return 0;
}


