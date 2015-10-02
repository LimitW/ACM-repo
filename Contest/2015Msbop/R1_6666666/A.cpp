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

int getv(char x){
	if(x == 'T') return 10;
	else if(x == 'J') return 11;
	else if(x == 'Q') return 12;
	else if(x == 'K') return 13;
	else if(x == 'A') return 1;
	else return x - '0';
}

int hs[15];

unsigned long long getv(int x){
	unsigned long long ans = 1;
	while(x > 1){
		ans *= x;
		x--;
	}
}


int main(){
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T ; ++kase){
		char t[53][4];
		memset(t,0,sizeof(t));
		memset(hs,0,sizeof(hs));
		int n; scanf("%d",&n);
		for(int i = 0; i < n; ++i){
			scanf("%s",t[i]);
			++hs[getv(t[i][0])];
		}
		unsigned long long ans = 0 , tmp = 1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				int th = hs[getv(t[i][0])] , cc = 0;
				for(int z = 1; z <= 13; ++z){
					if(z != th) cc += hs[z];
				}
				if(i == 0 || i == n-1){
					tmp *= cc;
				}
				tmp *= cc;
			}
		}
		printf("Case #%d:\n",kase);
	}
    return 0;
}

