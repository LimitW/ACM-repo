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

const int maxn = 1e6+2;

int pos[maxn];
int ot[maxn];
int st[1010];

int main(){
	int n,m,k,p;
	vector<int> T;
	while(~scanf("%d%d%d%d",&n,&m,&k,&p)){
		for(int i = 0; i < n; ++i)
			scanf("%d",&ot[i]);
		for(int i = 0; i < m; ++i)
			scanf("%d",&st[i]);
		T.clear(); T.push_back(1);
		while(1){
			int pn , cn , nxt;
			pn = (T.back() - 1) / (k + 1) + 1;
			cn = (n - 1) / (k + 1) + 1;
			if(T.back() % (k + 1) == 0) nxt = n - cn + pn - 1;
			else nxt = T.back() - pn;
			if(nxt == T[0]) break;
			else T.push_back(nxt);
		}
		for(int i = 1; i <= n; ++i){
			int np =
			pos[np] = ot[i-1];
		}
		int fail = 0;
		for(int i = 0; i < n; ++i){
			if(pos[i] == st[0]){
				for(int j = i + 1, k = 1; k < m && j < n; ++k , ++j)
					if(pos[j] != st[k]){
						fail = 1; break;
					}
				break;
			}
		}
		if(!fail) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}

