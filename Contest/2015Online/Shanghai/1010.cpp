#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

#define LL long long
#define pii pair<int,int>

const int maxn = 2e5 + 10;

pii p[110];
int n, l, a, b;

bool ok(int s){
	for(int i = 1; i <= n + 1; ++i){
		s += (p[i].first - p[i-1].second) * b;
		s -= (p[i].second - p[i].first) * a;
		if(s < 0) return 0;
	}
	return s >= 0;
}

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%d%d%d%d", &n, &a, &b, &l);
		p[0].first = p[0].second = 0;
		p[n+1].first = p[n+1].second = l;
		for(int i = 1; i <= n; ++i){
			scanf("%d%d", &p[i].first, &p[i].second);
		}
		int ll = 0, rr = 1e9, ans = 1e9;
		while(ll <= rr){
			int mid = ll + rr >> 1;
			if(ok(mid)){
				rr = mid - 1;
				ans = mid;
			}
			else ll = mid + 1;
		}
		printf("Case #%d: %d\n", kase, ans);
	}
    return 0;
}

