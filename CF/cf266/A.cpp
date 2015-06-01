/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.9.13
 * Source:Codeforces Round 266 A
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
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	int ans = INF;
	int ans1 = 0, ans2 = 0, ans3 = 0;
	ans1 = n * a;
	ans2 = n % m == 0 ? b * (n / m) : b * (n / m +1);
	ans3 = (n - n % m) * b / m + (n % m) * a;
	ans = min(ans1,ans2);
	ans = min(ans,ans3);
	printf("%d\n",ans);
	return 0;
}