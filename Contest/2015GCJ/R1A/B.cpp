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

int a[1010];

int main(){
	freopen("B-large-practice.in","r",stdin);
	freopen("B3.out","w",stdout);
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; ++kase){
		int m , n , ans; scanf("%d%d",&m,&n);
		for(int i = 0; i < m; ++i){
			scanf("%d",&a[i]);
		}
		long long l = 0 , r = 1e18;
		while(l < r){
			long long mid = (l + r) / 2;
			long long cnt = 0;
			for(int i = 0; i < m; ++i){
				cnt += mid / a[i] + 1;
			}
			if(cnt >= n) r = mid;
			else l = mid + 1;
		}
		long long sum = 0;
		for(int i = 0 ; i < m; ++i){
			sum += ( l - 1 ) / a[i] + 1;
		}
		for(int i = 0; i < m; ++i){
			if(l % a[i] == 0){
				sum++;
				if(sum == n){
					ans = i + 1; break;
				}
			}
		}
		printf("Case #%d: %d\n",kase,ans);
	}
    return 0;
}

