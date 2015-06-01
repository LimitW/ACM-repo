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
const int MOD = 1e9 + 7;

int main(){
	long long a,b;
	cin >> a >> b;
	long long ans = 0;
	for(int i = 1; i < b; i++)
    {
        ans += ( ((( ((b*i)%MOD)*(((a*(a+1)/2)%MOD) )%MOD)+ ((a*i)%MOD) ))  % MOD);
        ans %= MOD;
    }
	printf("%I64d\n",ans);
	return 0;
}
