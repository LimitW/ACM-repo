/************************************************
 * Title:X-Plosives
 * Author:LimitW
 * Date:2014.10.4
 * Source:LA 3644
 * Note:union-find set
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

int p[maxn];

int getfa(int x){
		return x == p[x] ? x : p[x] = getfa(p[x]);
	return x;
}

int main(){
	int x,y;
	while(scanf("%d",&x) == 1)
	{
		for(int i = 0; i < maxn; i++) p[i] = i;
		int refuse = 0;
		while(x != -1)
		{
			scanf("%d",&y);
			x = getfa(x); y = getfa(y);
			if(x == y) ++refuse;
			else p[x] = y;
			scanf("%d",&x);
		}
		printf("%d\n", refuse);
	}
	return 0;
}