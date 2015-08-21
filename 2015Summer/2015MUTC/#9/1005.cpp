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
const int maxn = 1e5 + 4;
//const int maxm = maxn * maxn;

int a[maxn];

int main(){
	int n, d1, d2;
	while(~scanf("%d%d%d", &n, &d1, &d2)){
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		LL ans = 0;
		for(int i = 1; i < n; ++i){
			LL l = 0;
			while(i + l < n && a[i+l] - a[i+l-1] == d1) ++l;
			while(i + l < n && a[i+l] - a[i+l-1] == d2) ++l;
			ans += (l + 1) * l / 2;
			i += l;
			if(l != 0) --i;
		}
		ans += n;
		cout << ans << '\n';
	}
    return 0;
}

