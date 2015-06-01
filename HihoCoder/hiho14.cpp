/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
*************************************************/

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
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

const int maxn = 1e5+5;

int p[maxn],r[maxn];

map<string,int> mp;
string ans[2] = {"no","yes"};

int Find(int x){
	return p[x] == x ? x : p[x]=Find(p[x]);
}

void Union(int x,int y){
	x = Find(x) ; y = Find(y);
	if(x != y) p[x] = y;
}

int main(){
	memset(r,0,sizeof(r));
	for(int i = 1; i <= maxn; i++) p[i] = i;
	int n , c = 0; scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		int op; string a,b; char aa[100], bb[100];
		scanf("%d%s%s",&op,aa,bb);
		a = aa; b = bb;
		if(mp.find(a) == mp.end()) mp[a] = ++c;
		if(mp.find(b) == mp.end()) mp[b] = ++c;
		if(op) cout << ans[(Find(mp[a]) == Find(mp[b]))] << '\n';
		else Union(mp[a],mp[b]);
	}
	return 0;
}

