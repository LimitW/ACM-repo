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
const long long INFL = 1LL << 62;

double dp[503];

int main(){
	memset(dp,0,sizeof(dp));
	dp[0] = 1.0; dp[1] = 2.0;
	for(int i = 2; i <= 500; ++i){
		double sum = 0;
		for(int j = i - 1; j >= 0; --j){
			sum += dp[j];
		}
		dp[i] = 2*sum / i;
	}
	int n; scanf("%d",&n);
	printf("%.6lf\n",dp[n]);
	return 0;
}

