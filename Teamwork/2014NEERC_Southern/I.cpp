#include <iostream>
#include <iomanip>
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
#include <utility>
#include <bitset>
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long

const int INF = 0x3f3f3f3f;

const int maxn = 2e3 + 10;

int main(){
	int n;
	int a[maxn];
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int s = a[n-1];
	int ans = 1, sum = 0;
	for(int i = 0; i < n-1; i++)
	{
		if(sum + a[i] <= s) { ans++; sum += a[i]; }
		else break;
	}
	printf("%d\n",ans);
	return 0;
}
