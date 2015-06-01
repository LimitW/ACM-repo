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

const int INF = 0x3fffffff;

int mp[110][110];

int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(mp,0,sizeof(mp));
		mp[1][n] = 1; mp[2][n] = 10; mp[2][n-1] = 1;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				printf("%d%c",mp[i][j],j == n ? '\n' : ' ');
	}
	return 0;
}
