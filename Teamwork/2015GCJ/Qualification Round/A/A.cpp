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
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; ++kase){
		int n; char a[1010];
		scanf("%d %s",&n,a);
		int cnt = a[0] - '0' , ans = 0;
		for(int i = 1; i <= n; ++i){
			if(cnt >= i) cnt += a[i] - '0';
			else { ans += i - cnt; cnt = a[i] - '0' + i; }
		}
		printf("Case #%d: %d\n",kase,ans);
	}
    return 0;
}

