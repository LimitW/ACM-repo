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
const long long INFL = 1LL << 62;

struct{
	int u,v;
}h[100010];

int main(){
	int n , m , fail = 0 , ans = 0;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		scanf("%d%d",&h[i].u,&h[i].v);
		ans = max(ans,h[i].v);
		if(i == 0){
			ans = max(ans , h[i].u - 1 + h[i].v);
		}
		if(i > 0){
			int d = abs(h[i].v - h[i-1].v);
			if(d > h[i].u - h[i-1].u) fail = 1;
			else {
				ans = max( ans , (h[i].v + h[i-1].v + h[i].u - h[i-1].u ) / 2 );
			}
		}
		if(i == m - 1){
			ans = max(ans , n - h[i].u + h[i].v);
		}
	}
	if(fail) printf("IMPOSSIBLE\n");
	else printf("%d\n",ans);
    return 0;
}

