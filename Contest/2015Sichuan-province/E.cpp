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

const int maxn = 1e5 + 1;

int main(){
	LL n, m, k, x, y;
	while(~scanf("%lld%lld%lld", &n, &m, &k)){
		k >>= 1;
		LL ans = 0;
		for(LL w = 1; w < min(k, n + 1); ++w){
			LL h = min(k - w, m);
			ans += (n - w + 1) * (m * h + h - h * (h + 1) / 2);
		}
		cout << ans << '\n';
	}
    return 0;
}
