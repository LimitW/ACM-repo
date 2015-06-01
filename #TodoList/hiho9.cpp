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

const int MOD = 1000000007;

int dp[1010][6][1<<11];

int main(){
	int n,m; scanf("%d%d",&n,&m);
	if(n * m % 2 != 0){
		puts("0"); return 0;
	}
	memset(dp,0,sizeof(dp));

	for(int i = n; i > 0; i--)
		for(int j = m; j > 0; j--)
			for(int s = (1<<(2*m-1)); s >= 0; s--){
				if((i == 1 || i == n) && (s < (1<<m))) continue;
				if (s & (1<<(j-1))){
					dp[i][j][s] =  j == m ? dp[i+1][1][(s<<m)&((1<<2*m)-(1<<m))] : dp[i][j+1][s];
				}
				else{
					int s1 = s & (1<<(j+m-1)) , s2 = s & (1<<(j-1));
					if(s1 == 0 && s2)
						dp[i][j][s] = dp[i][j][s^(1<<j)^(1<<(j-1))];
					else if(s1 && s2 == 0)
						dp[i][j][s] = dp[i][j][s^(1<<(j-1))^(1<<(j+m-1))];
					else if(s1 && s2){
						dp[i][j][s] = dp[i][j][s^(1<<(j-1))^(1<<(j+m-1))] + dp[i][j][s^(1<<j)^(1<<(j-1))];
						dp[i][j][s] %= MOD;
					}
				}
			}
	printf("%d\n",dp[1][1][0]);
    return 0;
}
