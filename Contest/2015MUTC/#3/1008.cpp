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

LL ql,qr,ans;

void dfs(LL l,LL r){
	if(l == r) { ans = r; return; }
	if(l == 0){
		ans = min(ans,r);
		return;
	}
	if(r < l || l < 0 || r > INF || 2ll*l-r-1 < 0) return;
	dfs(2ll*l-r-2,r);
	dfs(2ll*l-r-1,r);
	if(2ll*(r-l)+1-l > 0) return;
	dfs(l,2ll*r-l);
	dfs(l,2ll*r-l+1);
}

int main(){
	while(~scanf("%I64d%I64d",&ql,&qr)){
		ans = INFL;
		dfs(ql,qr);
		if(ans == INFL) ans = -1;
		printf("%I64d\n",ans);
	}
    return 0;
}

