#include <bits/stdc++.h>

using namespace std;

int n, h;

int d[30], f[30], t[30], sum[30];

int res[30], p[30][30];

struct node{
	int v, id, flag;
	node(int v = -1, int id = -1):v(v), id(id){ flag = 0; };
	bool operator < (node b) const {
		return v > b.v || (v == b.v && id < b.id);
	}
};

node c[10000];

void solve(int x){
	if(sum[x] > h) return;
	int k = 0;
	for(int i = 0; i <= x; ++i){
		int j = f[i];
		while(j > 0){
			c[k++] = node(j, i);
			if(d[i] == 0){
				c[k-1].flag = 1;
				break;
			}
			j -= d[i];
		}
	}
	sort(c, c + k);
	int m = min(h - sum[x], k);
	for(int i = 0; i < m; ++i){
		if(c[i].flag){
			res[x] += c[i].v * (h - sum[x] - i);
			p[x][c[i].id] += h - sum[x] - i;
			m = h - sum[x];
			break;
		}
		else{
			res[x] += c[i].v;
			++p[x][c[i].id];
		}
	}
	p[x][0] += h - sum[x] - m;
}

int main(){
	bool fs = 1;
	while(scanf("%d", &n) && n){
		memset(p, 0, sizeof(p));
		memset(res, 0, sizeof(res));
		scanf("%d", &h); h *= 12;
		if(!fs) puts("");
		else fs = 0;
		for(int i = 0; i < n; ++i)
			scanf("%d", f + i);
		for(int i = 0; i < n; ++i)
			scanf("%d", d + i);
		for(int i = 1; i < n; ++i){
			scanf("%d", t + i);
			sum[i] = sum[i-1] + t[i];
		}
		for(int i = 0; i < n; ++i)
			solve(i);
		int ans = -1;
		int cnt[30];
		for(int i = 0; i < n; ++i){
			int flag = 0;
			if(res[i] > ans){
				ans = res[i];
				flag = 1;
			}
			else if(res[i] == ans){
				for(int j = 0; j < n; ++j){
					if(p[i][j] > cnt[j]) flag = 1;
					if(p[i][j] != cnt[j]) break;
				}
			}
			if(flag){
				for(int j = 0; j < n; ++j)
					cnt[j] = p[i][j];
			}
		}
		for(int i = 0; i < n; ++i){
			printf("%d%s", cnt[i] * 5, i==n-1?"\n":", ");
		}
		printf("Number of fish expected: %d\n", ans);
	}
	return 0;
}

