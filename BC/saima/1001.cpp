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
const int maxn = 1e7 + 10;
unsigned int l[maxn] , r[maxn];

int main(){
	int T; scanf("%d",&T);
	while(T--) {
		int n;
		unsigned int a,b,c,d;
		scanf("%d%u%u%u%u%u%u",&n,&l[0],&r[0],&a,&b,&c,&d);
		unsigned int ll = 4294967295UL, rr = 0;
		for(int i = 1; i < n; ++i){
			l[i] = l[i-1] * a + b;
			r[i] = r[i-1] * c + d;
		}
		for(int i = 0; i < n; ++i){
			if(l[i] > r[i]) swap(l[i],r[i]);
			ll = min(r[i],ll);
			rr = max(l[i],rr);
		}
		bool fail = 1;
		for(int i = 0; i < n; ++i){
			if(l[i] > ll && r[i] < rr) { fail = 0; break; }
		}
		if(fail) printf("NO\n");
		else printf("YES\n");
	}
    return 0;
}

