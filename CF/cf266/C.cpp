/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.9.13
 * Source:Codeforces Round 266 C
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
const int maxn = 5e5 + 10;

long long s[maxn];

int main(){
	int n;
	cin >> n;
	s[0] = 0;
	for(int i = 0; i < n; i++){
		int foo;
		cin >> foo;
		s[i+1] = s[i] + foo;
	}
	long long ans = 0;
	if(s[n] % 3 == 0){
		long long u = s[n] / 3, v = 2 * s[n] / 3;
		long long cnt = 0;
		for(int i = 1; i < n; i++){
			if(s[i] == v)
				ans += cnt;
			if(s[i] == u)
				cnt++;
		}
	}
	cout << ans << endl;
	return 0;
}