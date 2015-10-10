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
const int maxn = 1e5 + 3;

int a[maxn], b[maxn], vis[maxn];

int main(){
	int T; scanf("%d", &T);
	for(int kase = 0; kase < T; ++kase){
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			int v; scanf("%d", &v);
			a[v] = i;
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%d", &b[i]);
			if(a[b[i]] == i) ++ans;
		}
		memset(vis, 0, sizeof(vis));
		int len, x;
		for(int i = 1; i <= n; ++i){
			if(!vis[i]){
				len = 0, x = i;
				while(!vis[x]){
					vis[x] = 1, ++len, x = b[a[x]];
		        }
		        ans += len - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}


