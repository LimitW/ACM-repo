/*
ID: LimitW
PROG: milk
LANG: C++11
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long
const int INF = 0x3f3f3f3f;
const int maxn = 5000 + 10;

pair<int,int> p[maxn];

int main(){
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
	int n,m; scanf("%d%d",&n,&m);
	for(int i = 0; i < m; i++)
		scanf("%d%d",&p[i].first,&p[i].second);
	sort(p,p+m);
	LL ans = 0;
	for(int i = 0; i < m && n; i++){
		ans += (LL) (min(n,p[i].second))*p[i].first;
		n = max(0,n-p[i].second);
	}
	printf("%lld\n",ans);
    return 0;
}
