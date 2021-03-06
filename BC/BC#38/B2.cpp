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
const long long INFL = 1LL << 62;

int hs[100010];
vector<int> g[100010];
//nlogn 求約數
void init(){
	for(int i = 2; i <= 100000; ++i){
		for(int j = i; j <= 100000; j += i){
			g[j].push_back(i);		
		}
	}
}


int main(){
	init();
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T ; ++kase){
		memset(hs,0,sizeof(hs));
		int n , mx = 0; scanf("%d",&n);
		for(int j = 0; j < n; ++j){
			int tmp; scanf("%d",&tmp);
			mx = max(mx,tmp);
			for(int i = 0; i < g[tmp].size(); ++i){
				++hs[g[tmp][i]];
			}
		}
		}
		for(int i = mx; i > 0 ;--i){
			if(hs[i] >= 2) {
				printf("Case #%d: %d\n",kase,i);
				break;
			}
		}
	}
    return 0;
}

