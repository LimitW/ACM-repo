/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.8.30
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

long long h[100010];

int main(){
	int n;
	cin >> n;
	h[0] = 0;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	long long pay = 0,energy = 0;
	for(int i = 1; i <= n; i++){
		energy += (h[i-1]-h[i]);
		if(energy < 0)
		{	
			pay -= energy;
			energy = 0;
		}
	}
	printf("%I64d\n",pay);
	return 0;
}