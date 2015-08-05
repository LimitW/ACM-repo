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

int a[maxn];

int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i = 0; i < n; ++i){
			scanf("%d",&a[i]);
		}
		if(n <= 2){
			printf("%d\n",n);
			continue;
		}
		int ans1 = 2, ans2 = 2;
		int d = a[1] - a[0], tmp = 2;
		for(int i = 2; i < n; ++i){
			if(a[i] - a[i-1] != d){
				d = a[i] - a[i-1];
				ans1 = max(ans1,tmp);
				tmp = 2;
			}
			else ++tmp;
		}
		ans1 = max(ans1,tmp);
		tmp = 2;
		double r = 1.0 * a[1] / a[0];
		for(int i = 2; i < n; ++i){
			if(1.0 * a[i] / a[i-1] != r){
				r = 1.0 * a[i] / a[i-1];
				ans2 = max(ans2,tmp);
				tmp = 2;
			}
			else ++tmp;
		}
		ans2 = max(tmp,ans2);
		printf("%d\n",max(ans1,ans2));
	}
    return 0;
}

