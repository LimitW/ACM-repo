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
const int maxn = 1e6 + 3;

int main(){
	int k;
	while(~scanf("%d",&k)){
		if(k < 10000){
			printf("%d\n",k);
			while(--k) printf("1 ");
			puts("1");
			continue;
		}
		LL n = 0;
		while(n * (n + 1) < 2 * k) ++n;
		LL v = n * (n + 1) - 2 * k;
		printf("%I64d\n",n);
		if(!v){
			for(int i = 1; i <= n; ++i)
				printf("%d%c", i, i == n ? '\n' : ' ');
			continue;
		}
		vector<int> ans;
		ans.clear();
		LL cnt = 0;
		while(v > 0){
			LL p = 1;
			while(p * (p - 1) <= v) ++p;
			ans.push_back(--p);
			cnt += p;
			v -= p * (p - 1);
		}
		cnt = n - cnt;
		for(int i = 1; i < ans.size(); ++i){
			int nn = ans[i-1];
			while(nn--) printf("%d ", i);
		}
		if(cnt > 0){
			int nn = ans.back(), vv = ans.size();
			while(nn--) printf("%d ", vv);
			while(cnt--) printf("%d%c", ++vv, cnt == 0 ? '\n' : ' ');
		}
		else{
			int nn = ans.back();
			while(nn--) printf("%d%c", ans.size(), nn == 0 ? '\n' : ' ');
		}
	}
    return 0;
}

