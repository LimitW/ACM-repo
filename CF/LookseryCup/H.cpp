//eps error....
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
#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const long double eps = 1e-10;

long double a[4];

pair<long double,long double> getv(long double aa[2],long double bb[2]){
	pair<long double,long double> x;
	if(aa[0] < 0 && aa[1] < 0){
		if(bb[0] < 0 && bb[1] < 0){
			x.second = aa[0] * bb[0];
			x.first = aa[1] * bb[1];
		}
		else if(bb[0] < 0 && bb[1] >= 0){
			x.second = aa[0] * bb[0];
			x.first = aa[0] * bb[1];
		}
		else {
			x.second = aa[1] * bb[0];
			x.first = aa[0] * bb[1];
		}
	}
	else if(aa[0] < 0 && aa[1] >= 0){
		if(bb[0] < 0 && bb[1] < 0){
			x.second = aa[0] * bb[0];
			x.first = aa[1] * bb[0];
		}
		else if(bb[0] < 0 && bb[1] > 0){
			x.second = max(bb[0] * aa[0] , aa[1] * bb[1]);
			x.first =  min(aa[1] * bb[0] , aa[0] * bb[1]);
		}
		else {
			x.second = aa[1] * bb[1];
			x.first = aa[0] * bb[1];
		}
	}
	else {
		if(bb[0] < 0 && bb[1] < 0){
			x.second = aa[1] * bb[0];
			x.first = aa[0] * bb[1];
		}
		else if(bb[0] < 0 && bb[1] >= 0){
			x.second = aa[1] * bb[1];
			x.first = aa[1] * bb[0];
		}
		else {
			x.second = aa[1] * bb[1];
			x.first = aa[0] * bb[0];
		}
	}
	if(x.first > x.second) swap(x.first,x.second);
	return x;
	/*vector<long double> z;
	z.push_back(aa[0]*bb[0]);
	z.push_back(aa[0]*bb[1]);
	z.push_back(aa[1]*bb[0]);
	z.push_back(aa[1]*bb[1]);
	sort(z.begin(),z.end());
	return make_pair(z[0],z[3]);*/
}

bool check(long double mid){
	long double x[4][2];
	for(int i = 0; i < 4; ++i){
		x[i][0] = a[i] - mid; x[i][1] = a[i] + mid;
		if(x[i][0] > x[i][1]) swap(x[i][0],x[i][1]);
	}
	bool ok = 0;
	pair<long double,long double> xx = getv(x[0],x[3]) , yy = getv(x[1],x[2]);
	if(xx.first > yy.first) swap(xx,yy);
	if(xx.second > yy.first) ok = 1;
	return ok;
}

int main(){
	cin >> a[0] >> a[1];
	cin >> a[2] >> a[3];
	long double l = 0.0 , r = 2e9;
	while(r - l > eps){
		long double mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	printf("%.10f\n",(double)(l+r)/2);
	return 0;
}
/*
-1000000000 0
0 1000000000
*/
