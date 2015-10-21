#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 3;
const int mod = 1e9 + 7;

int a[1010];

int main(){
	int n; scanf("%d", &n);
	int sum = 0, ans = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sum /= n;
	for(int i = 0; i < n; ++i){
		if(a[i] > sum) ++ans;
	}
	cout << ans << '\n';
	return 0;
}
