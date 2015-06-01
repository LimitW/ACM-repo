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
int a[maxn];

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
		int flag = a[0];
		for(int i = 1; i < n; i++)
			flag ^= a[i];
		if(flag == 0)
			printf("Lose\n");
		else
			printf("Win\n");
	}
	return 0;
}