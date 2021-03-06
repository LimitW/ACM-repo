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
	long long n,m,k;
	while(~scanf("%lld%lld%lld",&n,&m,&k)){
		if(k % 2 != 0) ++k;
		long long pow2 = pow(2.0,m);
		long long res = k - pow2 * 2 * n , ans = k - 2*n;
		if(res > 0) {
			ans += ((res % pow2 == 0) ? (res / pow2) : (res / pow2+1)) * 2;
		}
		if(ans > 1e16) ans = -1;
		printf("%lld\n",ans);
	}
    return 0;
}
