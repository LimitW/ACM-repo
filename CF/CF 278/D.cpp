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

const int maxn = 1e5 + 10;
int f[maxn] , g[maxn];
int a[maxn];

int main(){
	int n , s , l;
	scanf("%d%d%d",&n,&s,&l);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	multiset<int> S;
	for(int k = 0, i = 0; i < n; i++)
	{
		for(; !S.empty(); )
		{
			int v1 = *S.begin();
			int v2 = *(--S.end());
			if(abs(v1 - a[i]) <= s && abs(v2 - a[i]) <= s) break;
			S.erase(S.lower_bound(a[k]));
			k++;
		}
		g[i] = k;
		S.insert(a[i]);
	}
	S.clear();
	f[0] = 0;
	for(int k = 0, i = 1; i <= n; i++)
	{
		if(i - l >= 0) S.insert(f[i - l]);
		for(; k <= i - l && k < g[i - 1]; k++) S.erase(S.lower_bound(f[k]));
		f[i] = ( S.empty() ? INF : (*S.begin()) + 1 );
	}
	if(f[n] >= INF) f[n] = -1;
	printf("%d\n",f[n]);
	return 0;
}

