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

const int maxn = 5e4 + 3;

bitset<maxn> bs[5][300];
pii a[5][maxn];

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n, m; scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < 5; ++j){
				scanf("%d", &a[j][i].first);
				a[j][i].second = i;
			}
		for(int i = 0; i < 5; ++i)
			sort(a[i], a[i] + n);
		int s = sqrt(n) + 1, p = n / s;
		if(n % s != 0) ++p;
		for(int i = 0; i < p; ++i)
			for(int j = 0; j < 5; ++j)
				bs[j][i].reset();
		for(int j = 0; j < 5; ++j){
			for(int i = 0; i < n; ++i){
				bs[j][i/s].set(a[j][i].second);
			}
		}
		for(int j = 0; j < 5; ++j)
			for(int i = 0; i < p; ++i){
				if(i) bs[j][i] |= bs[j][i-1];
			}
		int ans = 0;
		int q; scanf("%d", &q);
		while(q--){
			bitset<maxn> res, tmp;
			res.set();
			for(int i = 0; i < 5; ++i){
				tmp.reset();
				int v; scanf("%d", &v);
				v ^= ans;
				int idx = lower_bound(a[i], a[i] + n, make_pair(v, n + 1)) - a[i] - 1;
				int curp = idx / s;
				if(curp > 0) tmp = bs[i][curp-1];
				for(int j = curp * s; j <= idx; ++j)
					tmp.set(a[i][j].second);
				res &= tmp;
			}
			ans = res.count();
			printf("%d\n", ans);
		}
	}
    return 0;
}

