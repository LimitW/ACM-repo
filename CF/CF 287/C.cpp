#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cstdlib>
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
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long
bool p[52];

int main(){
	int h; LL n; scanf("%d%lld",&h,&n);
	n = (1ll << h) + n - 1;
	int c = 0 , k = h;
	while(n > 1){
		if(n % 2){
			p[c] = 1;
			n -= 1;
		}
		n /= 2;
		c++;
	}
	LL ans = 0;
	if(p[--c]) ans += (1ll << k) - 1;
	ans++; k--; c--;
	for(; c >= 0; c--){
		if(p[c] == p[c+1]){
			ans += (1ll << k) - 1;
		}
		ans++; k--;
	}
	printf("%lld\n",ans);
	return 0;
}
