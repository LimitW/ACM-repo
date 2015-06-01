
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

int dp[10][10];

void init(){
	dp[0][0] = 1;
	for(int i = 1; i < 10; i++)
		for(int j = 1; j < 10; j++){
			dp[i][j] = dp[i-1][j-1] * j + dp[i-1][j] * j;
		}
}

int main(){
	init();
	int T; scanf("%d",&T);
	for(int  kase = 1; kase <= T; kase++){
		int n , b; scanf("%d%d",&n,&b);
		double ans = 0;
		for(int i = 1; i <= min(b,n); i++){
			double c = 1.0;
			for(int j = n; j > n - i; j--) c *= j;
			for(int j = 2; j <= i; j++) c /= j;
			c *= dp[b][i];
			for(int j = 1; j <= b; j++) c /= n;
			ans += 1.0 * (n+1) / 2 * i * c;
		}
		printf("Case #%d: %.3lf\n",kase,ans);
	}
    return 0;
}
