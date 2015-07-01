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

pii b[maxn];
map<int,vector<int> > hs;
int f[210];

int main(){
    memset(f,0,sizeof(f));
	int n; scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		scanf("%d",&b[i].first);
	}
	for(int i = 1; i <= n; ++i){
        scanf("%d",&b[i].second);
        ++f[b[i].second];
        hs[b[i].first].push_back(b[i].second);
	}
	sort(b+1,b+n+1,greater<pii>());
	int ans = INF , tmpw = 0 , tmpc = 0;
	map<int,vector<int> >::iterator it = hs.end();
	--it;
	while(1){
		int v = it->first;
		vector<int> nl = it->second;
		int nn = 2 * nl.size() - 1;
        int tmp2 = tmpw , cut = n - nn - tmpc;
        tmpc += nl.size();
		for(int i = 0; i < nl.size(); ++i){
		    --f[nl[i]];
            tmpw += nl[i];
		}
		for(int i = 0; i <= 200 && cut > 0; ++i){
            tmp2 += min(cut,f[i]) * i;
            cut -= f[i];
		}
		ans = min(ans,tmp2);
		if(it == hs.begin()) break;
		--it;
	}
	cout << ans << '\n';
    return 0;
}