/************************************************
 * Title:
 * Author:LimitW
 * Date:
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

int cmp(const double a,const double b){
	return a > b;
}
double mpow(double x,int n){
	double ans = 1.0;
	while(n--)
		ans *= x;
	return ans;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		double a[60];
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a,a+n,cmp);
		double sum = 0.0;
		for(int i = 0; i < n; i++)
			sum += mpow(0.95,i)*a[i];
		printf("%.10lf\n",sum);
	}
	return 0;
}