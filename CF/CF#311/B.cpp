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

int a[200010];

int n,w;

bool check(double x){
	x /= (3.0 * n);
	if(x <= a[0] && 2.0 * x <= a[n])
		return 1;
	else return 0;
}

int main(){
    cin >> n >> w;
	for(int i = 0; i < 2 * n; ++i){
		cin >> a[i];
	}
	sort(a,a+2*n);
	double l = 0.0 , r = w * 1.0;
	while(r - l >= 1e-6){
		double mid = (r + l) / 2.0;
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%.6lf\n",(l+r)/2.0);
    return 0;
}
