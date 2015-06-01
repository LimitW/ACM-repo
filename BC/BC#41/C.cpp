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
#include <fstream>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const long long INFL = 1LL << 62;

const int mod = 998244353;

int dp[100010][320];

void solve(){
	for(int i = 1; i <= 100000; i++){
		for(int j = 1; j <= 320; j++){
			if(j == 1) dp[i][j] = 1;
			else dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
			if(dp[i][j] > mod) dp[i][j] -= mod;
        }
    }
}

int main(){
	solve();
	int T; cin >> T;
	for(int kase = 0; kase < T; ++kase){
		int n,c,l,r; scanf("%d%d%d%d",&n,&c,&l,&r);
		int ans = 0;
		for(int i = l - c; i <= r - c; ++i)
			for(int j = 1; j * j <= i; ++j)
				ans = (ans + dp[i][j]) % mod;
		printf("%d\n",ans);
	}
	return 0;
}

