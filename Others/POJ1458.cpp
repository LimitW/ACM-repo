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
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

const int maxn = 1000+10;
int dp[maxn][maxn];

int LCS(char* a,char* b,int p,int q){
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= p; i++)
		for(int j = 1; j <= q; j++)
		{
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	return dp[p][q];
}

int main(){
	char a[1010] , b[1010];
	while(scanf("%s%s",&a,&b) != EOF){
		int p = strlen(a) , q = strlen(b);
		printf("%d\n",LCS(a,b,p,q));
	}
	return 0;
}
