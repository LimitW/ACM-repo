#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

#define LL long long
#define pii pair<int,int>

const int maxn = 2e5 + 10;

int n, m;

struct node{
	int l, r;
	LL v;
}st[maxn<<2];

void pushup(int o){
	st[o].v = st[o<<1].v * st[o<<1|1].v % m;
}

void build(int o, int l, int r){
	st[o].l = l, st[o].r = r;
	if(l == r){
		st[o].v = 1;
		return;
	}
	int mid = l + r >> 1;
	build(o<<1, l, mid);
	build(o<<1|1, mid+1, r);
	pushup(o);
}

void update(int o, int x, LL v){
	if(st[o].l == st[o].r && st[o].l == x){
		st[o].v = v;
		return;
	}
	int mid = st[o].l + st[o].r >> 1;
	if(x > mid) update(o<<1|1, x, v);
	else update(o<<1, x, v);
	pushup(o);
}

LL query(int o, int l, int r){
	if(st[o].l == l && st[o].r == r)
		return st[o].v;
	int mid = st[o].l + st[o].r >> 1;
	if(l > mid) return query(o<<1|1, l, r);
	else if(r <= mid) return query(o<<1, l, r);
	else return query(o<<1, l, mid) * query(o<<1|1, mid+1, r) % m;
}

int main(){
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		printf("Case #%d:\n", kase);
		scanf("%d%d", &n, &m);
		build(1, 1, n);
		for(int i = 1; i <= n; ++i){
			int op, v; scanf("%d%d", &op, &v);
			if(op == 1){
				update(1, i, v);
				printf("%d\n", (int)st[1].v);
			}
			else{
				update(1, v, 1);
				printf("%d\n", (int)st[1].v);
			}
		}
	}
    return 0;
}

