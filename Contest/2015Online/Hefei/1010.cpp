#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 3;

int st[maxn<<2], ans[maxn];

void pushup(int o){
	st[o] = st[o<<1] + st[o<<1|1];
}

void build(int o, int l, int r){
	if(l == r){
		st[o] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(o<<1, l, mid);
	build(o<<1|1, mid+1, r);
	pushup(o);
}

void update(int o, int l, int r, int p, int v){
	if(l == r){
		st[o] = 0;
		ans[l] = v;
		return;
	}
	int mid = l + r >> 1;
	if(p <= st[o<<1]) update(o<<1, l, mid, p, v);
	else update(o<<1|1, mid+1, r, p - st[o<<1], v);
	pushup(o);
}

struct peo{
	int h, k;
	bool operator < (peo b) const{
		return h < b.h;
	}
}p[maxn];

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		int n; scanf("%d", &n);
		build(1, 1, n);
		for(int i = 1; i <= n; ++i){
			scanf("%d%d", &p[i].h, &p[i].k);
		}
		sort(p + 1, p + n + 1);
		bool fail = 0;
		for(int i = 1; i <= n; ++i){
			int cnt = n - i;
			if(cnt < p[i].k){
				fail = 1;
				break;
			}
			cnt = min(cnt - p[i].k, p[i].k) + 1;
			update(1, 1, n, cnt, p[i].h);
		}
		if(fail) printf("Case #%d: impossible\n", kase);
		else{
			printf("Case #%d: ", kase);
			for(int i = 1; i <= n; ++i){
				printf("%d%c", ans[i], i == n ? '\n' : ' ');
			}
		}
	}
	return 0;
}

