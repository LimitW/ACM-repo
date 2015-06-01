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

struct Tuple {
	int l , r , v;
}c[1010];

int a[1010];

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}

int main(){
	int T; scanf("%d",&T);
	while(T--) {
		int n,q; scanf("%d%d",&n,&q);
		for(int i = 0; i < q; ++i) {
			scanf("%d%d%d",&c[i].l,&c[i].r,&c[i].v);
		}
		memset(a,-1,sizeof(a));
		bool fail = 0;
		for(int i = 0; i < q; ++i){
			for(int j = c[i].l; j <= c[i].r; ++j){
				if(a[j] % c[i].v == 0 || c[i].v % a[j] == 0) a[j] = max(a[j],c[i].v);
				else a[j] = lcm(c[i].v,a[j]);
			}
		}
		if(fail) { puts("Stupid BrotherK!"); continue; }
		for(int i = 1; i <= n; ++i) {
			if(a[i] == -1) a[i] = 1;
			else if(a[i] > 1e9 || a[i] <= 0) fail = 1;
		}
		for(int i = 0; i < q; ++i){
			int gd = a[c[i].l];
			for(int j = c[i].l + 1; j <= c[i].r; ++j){
				gd = gcd(gd,a[j]);
			}
			if(gd != c[i].v) { fail = 1; break; }
		}
		if(fail) puts("Stupid BrotherK!");
		else {
			for(int i = 1; i <= n; ++i){
				printf("%d%c" , a[i] , i == n ? '\n' : ' ');
			}
		}
	}
    return 0;
}

