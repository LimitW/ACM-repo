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
#include <ctime>
using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

//枚举分成的最小的数
int a[1010];

int main(){
	freopen("B-large-practice.in","r",stdin);
	freopen("test.out","w",stdout);
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; ++kase){
		int D; scanf("%d",&D);
		for(int i = 0; i < D; ++i)
			scanf("%d",&a[i]);
		int ans = INF;
		for(int i = 1; i <= 1000; ++i){
			int mn = i;
			for(int j = 0; j < D; ++j)
				mn += (a[j] - 1) / i;
			if(ans > mn) ans = mn;
		}
		printf("Case #%d: %d\n",kase,ans);
	}
    return 0;
}

