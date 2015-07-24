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
const int mod = 360*12000;

struct tt{
	int h,m,s;
	tt(int hh,int mm,int ss):h(hh),m(mm),s(ss){}
	bool operator < (tt b) const {
		return h < b.h || (h == b.h && m < b.m) || (h == b.h && m == b.m && s < b.s);
	}
	bool operator == (tt b) const {
		return ((h == b.h) && (m == b.m)) && (s == b.s);
	}
};

vector<tt> ans;

int main(){
	int diff[2];
	while(~scanf("%d",&diff[0])){
		diff[1] = mod - diff[0];
		ans.clear();
		for(int hh = 0; hh < 12; ++hh)
			for(int ss = 0; ss < 60; ss += 10)
				for(int _ = 0; _ < 2; ++_){
				int mm[2];
				mm[0] = (30*hh*12000 - 1100*ss - diff[_]) / (72000-6000),
				mm[1] = (30*hh*12000 - 1100*ss + diff[_]) / (72000-6000);
				for(int j = 0; j < 2; ++j){
					if(j && mm[j] == mm[j-1]) continue;
					if(mm[j] >= 60 || mm[j] < 0) continue;
					int fh = 30*hh*12000 + 6000*mm[j] + 100*ss , fm = 72000*mm[j] + 1200*ss;
					fh %= mod; fm %= mod;
					if(abs(fh-fm) == diff[_])
						ans.push_back(tt(hh,mm[j],ss));
				}
			}
		sort(ans.begin(),ans.end());
		int sz = unique(ans.begin(),ans.end()) - ans.begin();
		for(int i = 0; i < sz;++i){
			printf("%02d:%02d:%02d\n",ans[i].h,ans[i].m,ans[i].s);
		}
	}
    return 0;
}

