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

int main(){
	int n,m;
	cin >> n >> m;
	int k = n % 2 == 0 ? n/2 : (n - 1) /2 ;
	for(int i = k; i <= n; i++)
		if(m % i == 0)
		{
			printf("%d\n",i);
			break;
		}
	return 0;
}