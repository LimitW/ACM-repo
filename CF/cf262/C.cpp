/*
 * Title:
 * Author:LimitW
 * Date:2014.8.21
 * Source:Codeforces round 262 C
 * Note:二分
*/

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

#define maxn 100000+10

int num[maxn];
int n,m,w;
int a[maxn];

bool check(long long x){
	long long moves = 0;
	memset(a,0,sizeof(a));
	long long cur = 0;
	for(int i = 0; i < n && moves <= m; i++){
		cur -= a[i];
		if(num[i] + cur < x){
			long long add = x - num[i] - cur;
			moves += add;
			cur += add;
			a[min(n,i+w)] += add;
		}
	}
	return moves <= m;
}

int main(){
	cin >> n >> m >> w;
	int i;
	for(i = 0; i < n; i++)
		cin >> num[i];
	long long l = 1, r = 2000000000;
	long long ans;
	while(l <= r){
		long long mid = (l + r) / 2;
		if(check(mid)){ l = mid + 1; ans = mid;}
		else r = mid - 1;
	}
	printf("%d\n",ans);
	return 0;
}