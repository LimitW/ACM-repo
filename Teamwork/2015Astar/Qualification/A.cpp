#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

const int mod = 1000000007;

long long dp[1000010];

int main(){
	dp[1] = 1; dp[2] = 2;
	for(long long i = 3; i <= 1000000; ++i){
		dp[i] = dp[i-1] + (i - 1) * dp[i-2];
		dp[i] %= mod;
	}
    int T; cin >> T;
    for(int kase = 1; kase <= T; ++kase){
    	int n; cin >> n;
    	printf("Case #%d:\n%d\n",kase,(int)dp[n]);
    }
    return 0;
}

