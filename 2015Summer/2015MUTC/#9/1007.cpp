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
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 100 + 4;
//const int maxm = maxn * maxn;

int g[maxn][maxn];

void col(int n, int m, int flag){
	for(int i = 1; i <= m; ++i){
		for(int j = 0; j < n - 1; ++j){
			if(i == m && j == n - 2) break;
			if(flag) printf("%c", i & 1 ? 'U' : 'D');
			else printf("%c", i & 1 ? 'D' : 'U');
		}
		if(i != m) putchar('R');
	}
}

void row(int n, int m, int flag){
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < m - 1; ++j){
			if(i == n && j == m - 2) break;
			if(flag) printf("%c", i & 1 ? 'L' : 'R');
			else printf("%c", i & 1 ? 'R' : 'L');
		}
		if(i != n) putchar('D');
	}
}

int main(){
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		int cnt = 0, mx = INF;
		pii p;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j){
				scanf("%d", &g[i][j]);
				cnt += g[i][j];
				if((i + j) & 1){
					if(mx > g[i][j]){
						mx = g[i][j];
						p.first = i, p.second = j;
					}
				}
			}
		if(n & 1){
			printf("%d\n", cnt);
			row(n, m, 0);
			putchar('R');
		}
		else if(m & 1){
			printf("%d\n", cnt);
			col(n, m, 0);
			putchar('D');
		}
		else{
			printf("%d\n", cnt-mx);
			int x = p.first - 2;
			if(p.first & 1) ++x;
			row(x, m, 0);
			if(x > 0){
				putchar(x & 1 ? 'R' : 'L');
				putchar('D');
			}
			col(2, p.second, 0);
			if(p.second < m){
				putchar('R');
				col(2, m - p.second, !(p.second & 1));
				putchar('D');
			}
			if(x + 2 < n){
				putchar('D');
				row(n - x - 2, m, 1);
				putchar('R');
			}
		}
		puts("");
	}
    return 0;
}

