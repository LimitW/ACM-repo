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

struct point {
	int x,y;
}p[2010];

double getv(point a,point b){
	if(a.y == b.y)
		return (double)INF;
	else return double(a.x - b.x) / (a.y - b.y);
}

int main(){
	int n; scanf("%d",&n);
	for(int i = 0; i < n; ++i)
		scanf("%d%d",&p[i].x,&p[i].y);
	LL ans = n * 1LL * (n - 1) * (n - 2) / 6;
	// don't forget beijing onsite 2014
	// the same mistake
	for(int i = 0; i < n; ++i){
		map<double,int> mp; mp.clear();
		for(int j = i+1; j < n; ++j)
			++mp[getv(p[i],p[j])];
		map<double,int>::iterator it = mp.begin();
		for(;it != mp.end();++it){
			ans -= (LL)(it->second) * (it->second - 1) / 2;
		}
	}
	printf("%lld\n",ans);
    return 0;
}

