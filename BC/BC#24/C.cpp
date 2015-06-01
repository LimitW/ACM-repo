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
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const double g = 9.8;
const double eps = 1e-5;
double h,v;

double f(double cos2){
	double sin2 = 1-cos2*cos2;
	return v*cos2*(v*sqrt(sin2) + sqrt(v*v*sin2+2*g*h))/g;
}

int main(){
	int T; scanf("%d",&T);
	for(int i = 0;i < T; i++){
		scanf("%lf%lf",&h,&v);
		double left = 0 , right = 1;
		double mid , midmid;
		double mid_value , midmid_value;
		double ans = 0;
		while(left + eps < right){
			mid = (left + right) / 2;
			midmid = (mid + right) / 2;
			mid_value = f(mid);
			midmid_value = f(midmid);
			ans = max(mid_value,midmid_value);
			if(mid_value > midmid_value) right = midmid;
			else left = mid;
		}
		printf("%.2lf\n",ans);
	}
    return 0;
}
