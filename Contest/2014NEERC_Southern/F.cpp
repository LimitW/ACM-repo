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

const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;

LL f[maxn];
LL csum[maxn];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	LL sum = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%I64d",&f[i]);
		sum += f[i];
	}
	if(n <= 2 * k) {
		printf("%I64d\n",sum); return 0;
	}
	memset(csum,0,sizeof(csum));
	for(int i = 1; i <= 2 * k; i++)
		csum[0] += f[ i ];
	for(int i = 1; i <= n - 2 * k ; i++)
		csum[ i ] = csum[ i - 1 ] + f[ i + 2 * k ] - f[ i ];
	sort(csum , csum + n - 2 * k + 1);
	LL cans = csum[n - 2 * k];
	memset(csum,0,sizeof(csum));
	for(int i = 1; i <= k; i++)
		csum[0] += f[ i ];
	for(int i = 1; i <= n - k ; i++)
		csum[ i ] = csum[ i - 1 ] + f[ i + k ] - f[ i ];
	LL sum1 = csum[0] , sum2 = csum[k + 1];
	LL uans = sum1 + sum2;
	int i = 1 ,  j = k + i + 2;
	while( j <= n - k + 1 )
	{
		sum1 = max(sum1, csum[i++]);
		sum2 = csum[j - 1];
		uans = max(uans,sum1 + sum2);
		j++;
	}
	printf("%I64d\n",max(uans,cans));
	return 0;
}