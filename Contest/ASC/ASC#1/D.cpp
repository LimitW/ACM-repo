/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
*************************************************/

#include <iostream>
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
#include <bitset>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
long long d[maxn];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(d,0,sizeof(d));
	for(int i = 0; i < m; i++)
	{
		int to,next;
		scanf("%d%d",&to,&next);
		d[to]++;
		d[next]++;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += d[i]*d[i];
	}
	printf("%I64d\n",ans);
	//system("pause");
	return 0;
}