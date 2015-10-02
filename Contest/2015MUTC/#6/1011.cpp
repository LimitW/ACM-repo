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
const int maxn = 1e6 + 3;

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
	int T; scanf("%d",&T);
	for(int i = 0; i < T; ++i){
		long long n; scanf("%I64d",&n);
		printf("%I64d\n",quickpow(2,n-1)-1);
	}
	return 0;
}

