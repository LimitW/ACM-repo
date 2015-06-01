/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.8.27
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
const int maxn = 3e5;
long long a[maxn+10];
long long s[maxn+10];
int main(){
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a,a+n);
	for(int i = 1; i < n; i++)
		sum = sum + i*a[i-1];
	if(n > 1) sum += (n-1)*a[n-1];
	printf("%I64d\n",sum);
	return 0;
}