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

const LL mod = 1000000007;

int a[1010] , sum[1010];

int main(){
	LL C[1010][1010];
	memset(C,0,sizeof(C));
	C[0][0]= 1; C[0][1] = 0;
	for(int i = 1 ; i <= 1000; ++i){
		C[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	int k; cin >> k;
	sum[0] = 0;
	for(int i = 1; i <= k; ++i){
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	LL ans = 1;
	for(int i = 2; i <= k; ++i){
		ans *= C[sum[i]-1][a[i]-1];
		ans %= mod;
	}
	cout << ans << '\n';
	return 0;
}

