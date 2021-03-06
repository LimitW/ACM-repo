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

LL powd[9];

LL getd(LL n){
	if(n == 0) return 1;
	int ans = 0;
	while(n > 0){
		n /= 10;
		++ans;
	}
	return ans;
}

int main(){
	powd[0] = 1;
	for(int i = 1; i <= 9; ++i){
		powd[i] = 10 * powd[i-1];
	}
	LL ans = 0 , n;
	cin >> n;
	LL md = getd(n);
	for(; md > 0; --md){
		ans += (LL) md * (n - powd[md-1] + 1);
		n = powd[md-1] - 1;
	}
	cout << ans << endl;
    return 0;
}

