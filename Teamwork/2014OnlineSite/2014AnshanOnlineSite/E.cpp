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
const int maxn = 50+5;
vector<int> vec[maxn];
double p[maxn];
int d[maxn][maxn];

int main(){
	int T;
	while(T--){
		int n,m,d;
		scanf("%d%d%d",&n,&m,&d);
		for(int i = 0; i < m; i++)
		{
			int b,e;
			scanf("%d%d",&b,&e);
			vec[b].push_back(e);
			vec[e].push_back(b);
		}
		for(int i = 0; i < n; i++){
			
		}
	}
	return 0;
}