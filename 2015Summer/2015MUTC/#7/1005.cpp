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
const int mod = 11;
const int maxn = 1e5+3;
//const int maxm = maxn * maxn;

int getl(int x){
	int ans = 0;
	while(x > 0){
		ans++;
		x /= 10;
	}
	return ans;
}
int getv(int x){
	int ans = 0;
	while(x > 0){
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

long long quickpow(long long m,long long n){
	long long ans = 1;
	while(n){
		if(n&1) ans = ans * m % mod;
		n >>= 1;
		m = m * m % mod;
	}
	return ans;
}

int main(){
	int n, t, kase = 0;
	while(~scanf("%d%d", &n, &t)){
		if(n == -1 || t == -1) break;
		int sum[maxn];
		sum[0] = getv(n);
		int x = n % 11;
		for(int i = 1; i <= t; ++i){
			x = (x * quickpow(10,getl(sum[i-1])) % 11 + sum[i-1] % 11) % 11;
			sum[i] = sum[i-1] + getv(sum[i-1]);
		}
		printf("Case #%d: ",++kase);
		if(!x) puts("Yes");
		else puts("No");
	}
    return 0;
}

