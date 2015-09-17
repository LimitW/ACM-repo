#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const long double eps = 1e-9;

int main(){
	double a, b;
	cin >> a >> b;
	if(a < b) puts("-1");
	else if(a == b) printf("%.9f\n", b);
	else{
		int k = (a - b) / 2 / b;
		double ans = (a - b) / 2 / k;
		k = (a + b) / 2 / b;
		ans = min(ans, (a + b) / 2 / k);
		printf("%.9f\n", ans);
	}
	return 0;
}

