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
const double pi = acos(-1.0);
const long double eps = 1e-9;
const int mod = 1e9 + 7;
const int maxn = (1 << 10) + 3;

LL powmod(LL x, LL y){
	LL ans = 1;
	while(y--) ans = ans * x % mod;
	return ans;
}

class LineMSTDiv2{
public:
	int count(int N){
		LL ans = 0;
		int st = 1 << N - 1;
		for(int i = 0; i < st; ++i){
			LL cnt = 1;
			for(int j = 0; j < N - 1; ++j){
				int k = j;
				while(i & (1 << k)) ++k;
				if(k > j){
					cnt *= powmod(2, k - j - 1);
					cnt %= mod;
				}
			}
			ans += cnt; ans %= mod;
		}
		for(int i = 3; i <= N; ++i){
			ans = ans * i % mod;
		}
		return (int)ans;
	}
};

