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
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 3;
const int maxm = 2e5 + 3;
const double eps = 1e-6;

double a, b, c;
double xx, yy;

double f(double x){
	return a * x * x + b * x + c;
}

double g(double x){
	return sqrt( (x - xx) * (x - xx) + (f(x) - yy) * (f(x) - yy));
}

int main(){
	while(~scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &xx, &yy)){
		double mid, midmid;
		double l = -200.0, r = 200.0;
		while(r - l > eps){
			mid = l + r; mid /= 2.0;
			midmid = mid + r; midmid /= 2.0;
			double midmidv = g(midmid), midv = g(mid);
			if(midmidv > midv) r = midmid;
			else l = mid;
		}
		printf("%.3lf\n",g(l));
	}
	return 0;
}

