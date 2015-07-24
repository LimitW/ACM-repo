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
const int mod = 1e9 + 7;

int a[100010];
vector<int> vis[10005];
vector<int> g[10005];

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i = 1; i <= n; ++i){
			scanf("%d",&a[i]);
			vis[a[i]].push_back(i);
		}
		for(int i = 1; i <= n; ++i){
			g[a[i]].clear();
			for(int j = 1; j * j <= a[i]; ++j){
				if(a[i] % j != 0) continue;
				int sz = vis[j].size();
				if(sz > 0){
					for(int k = 0; k < sz; ++k)
						g[a[i]].push_back(vis[j][k]);
				}
				sz = vis[a[i]/j].size();
				if(j * j != a[i] && sz > 0){
					for(int k = 0; k < sz; ++k)
						g[a[i]].push_back(vis[a[i]/j][k]);
				}
			}
		}
		LL ans = 0;
		for(LL i = 1; i <= n; ++i){
			int sz = g[a[i]].size();
			LL tmp = 0, tmp2 = n + 1;
			for(int j = 0; j < sz; ++j){
				LL p = (LL) g[a[i]][j];
				if(p < i) tmp = max(tmp,p);
				else if(p > i) tmp2 = min(tmp2,p);
			}
			ans += (i-tmp)*(tmp2-i);
		}
		printf("%d\n",(int)(ans%mod));
		for(int i = 1; i <= n; ++i)
			vis[a[i]].clear();
	}
    return 0;
}

