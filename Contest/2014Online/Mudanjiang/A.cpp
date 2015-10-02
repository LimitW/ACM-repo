/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.9.7
 * Source:2014 Mudanjiang Online A
 * Note:签到题
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
int a[10010];
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = 0;
		for(int i = 2; i <= n - 1; i++)
			if(a[i]> a[i-1] && a[i] > a[i+1])
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}