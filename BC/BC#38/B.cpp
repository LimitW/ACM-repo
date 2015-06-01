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

int main(){
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T ; ++kase){
		memset(hs,0,sizeof(hs));
		int n , mx = 0; scanf("%d",&n);
		for(int j = 0; j < n; ++j){
			int tmp; scanf("%d",&tmp);
			mx = max(mx,tmp);
			for(int i = 1; i * i <= tmp; ++i) // i <= sqrt(tmp)超时
				if(tmp % i == 0){
					++hs[i];
					if(tmp / i != i) ++hs[tmp/i];
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

