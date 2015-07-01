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

map<int,pair<char,int> > mp;

int query(int x,char c){
	map<int,pair<char,int> >::iterator u = mp.lower_bound(x);
	if(x == u->first) return 0;
	if(c == 'L') --u;
	int ans = abs(u->first-x);
	if(c == u->second.first){
		ans += u->second.second;
	}
	mp[x] = {c,ans};
	return ans;
}

int main(){
	int n,q; scanf("%d%d",&n,&q);
	mp[0] = {'U',0};
	mp[n+1] = {'L',0};
	for(int i = 0; i < q; ++i){
		int x,y; char c;
		scanf("%d %d %c",&x,&y,&c);
		printf("%d\n",query(x,c));
	}
    return 0;
}
