#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const long double eps = 1e-9;

long long a[200010], pre[200010], suf[200010];

int main(){
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	for(int i = 0; i < n; ++i)
		scanf("%I64d", &a[i]);
	pre[0] = a[0];
	for(int i = 1; i < n; ++i)
		pre[i] = pre[i-1] | a[i];
	suf[n-1] = a[n-1];
	for(int i = n - 2; i >= 0; --i)
		suf[i] = suf[i+1] | a[i];
	long long mul = 1ll, ans = -1;
	while(k--) mul *= x;
	for(int i = 0; i < n; ++i){
		long long tmp = a[i] * mul;
		if(i - 1 >= 0) tmp |= pre[i-1];
		if(i + 1 < n) tmp |= suf[i+1];
		ans = max(ans, tmp);
	}
	cout << ans << '\n';
	return 0;
}

