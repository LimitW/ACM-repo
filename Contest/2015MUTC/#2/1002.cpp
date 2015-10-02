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

int main(){
	int n,m,x,y;
	while(~scanf("%d%d%d%d",&n,&m,&x,&y)){
		int ans = min((n+1)/2,(m+1)/2);
		if(n <= m && min(n-x+1,x) > ans)
			ans = min(min(n-x+1,x),max(m - y, y - 1));
		if(n >= m && min(m-y+1,y) > ans)
			ans = min(min(m-y+1,y),max(n - x, x - 1));
		if(n % 2 && n == m && x == (n + 1) / 2 && x == y)
			--ans;
		if(n == 1 && m == 1) ans = 0;
		printf("%d\n",ans);
	}
	return 0;
}

