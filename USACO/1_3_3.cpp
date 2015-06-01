/*
ID: LimitW
PROG: crypt1
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
#include <cctype>
#include <cassert>
using namespace std;

#define LL long long
const int INF = 0x3f3f3f3f;

bool vis[11];

bool is_cy(int x){
	if(x == 0) return false;
	while(x) {
		int bit = x % 10;
		if(!vis[bit]) return false;
		x /= 10;
	}
	return true;
}

int main(){
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
	int n; scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	vector<int> digit(n);
	for(int i = 0; i < n; i++){
		scanf("%d",&digit[i]);
		vis[digit[i]] = true;
	}
	int ans = 0;
	for(int a : digit)
		for(int b : digit)
			for(int c : digit)
				for(int d : digit)
					for(int e : digit)
					{
						int p1 = e*(100*a+10*b+c); if(p1 >= 1000) continue;
						int p2 = d*(100*a+10*b+c); if(p2 >= 1000) continue;
						int p = p1 + p2 * 10; if(p < 1000 || p >= 10000) continue;
						if(is_cy(p1) && is_cy(p2) && is_cy(p))
							ans++;
					}
	printf("%d\n",ans);
    return 0;
}
