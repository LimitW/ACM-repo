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


vector<int> hs[mod/2+1];

void init(){
	for(int hh = 0; hh < 12; ++hh)
		for(int mm = 0; mm < 60; ++mm)
			for(int ss = 0; ss < 60; ss+=10){
				int fh = 30*hh*12000 + 6000*mm + 100*ss ,fm = 72000*mm + 1200*ss;
				int ang = abs(fh - fm);
				if(ang > 180*12000) ang = mod - ang;
				hs[ang].push_back(hh*3600+mm*60+ss);
			}
}

int main(){
	init();
	int diff;
	while(~scanf("%d",&diff)){
		sort(hs[diff].begin(),hs[diff].end());
		int sz = hs[diff].size();
		for(int i = 0; i < sz; ++i){
			int hh = hs[diff][i] / 3600 , mm = (hs[diff][i]-3600*hh)/60 ,
					ss = hs[diff][i]-3600*hh -60*mm;
			printf("%02d:%02d:%02d\n",hh,mm,ss);
		}
	}
    return 0;
}

