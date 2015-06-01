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

typedef pair<int,int> interval;

interval it[100010];
int a[100010];

int main(){
	int n;
	scanf("%d",&n);
	int tot = 1;
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		it[i] = make_pair(tot,tot+a[i]-1);
		tot += a[i];
	}
	int m;
	scanf("%d",&m);
	for(int i = 0; i < m; i++)
	{
		int q;
		scanf("%d",&q);
		int l = 1, r = n;
		while(l <= r){
			int m = l + (r - l) / 2;
			if(q > it[m].second) l = m+1;
			else if(q < it[m].first) r = m;
			else{
				printf("%d\n",m);
				break;
			}
		}
	}
	//system("pause");
	return 0;
}
