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

int main(){
	freopen("D-small-attempt3.in","r",stdin);
	freopen("D4.out","w",stdout);
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; ++kase){
		int ans[5][5][5] , x , r ,c;
		memset(ans,0,sizeof(ans));
		scanf("%d%d%d",&x,&r,&c);
		if(x == 1){
			printf("Case #%d: GABRIEL\n",kase);
			continue;
		}
		ans[2][1][2] = 1; ans[2][1][4] = 1;
		ans[2][2][1] = 1; ans[2][2][2] = 1;
		ans[2][2][3] = 1; ans[2][2][4] = 1;
		ans[2][3][2] = 1; ans[2][3][4] = 1;
		ans[2][4][1] = 1; ans[2][4][2] = 1;
		ans[2][4][3] = 1; ans[2][4][4] = 1;
		ans[3][2][3] = 1; ans[3][3][2] = 1;
		ans[3][3][3] = 1; ans[3][3][4] = 1;
		ans[3][4][3] = 1; ans[4][4][4] = 1;
		ans[4][3][4] = 1; ans[4][4][3] = 1;
		if(ans[x][r][c]) printf("Case #%d: GABRIEL\n",kase);
		else printf("Case #%d: RICHARD\n",kase);
	}
    return 0;
}

