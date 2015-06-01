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

double a,b;

int main(){
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; kase++)
	{
		scanf("%lf%lf",&a,&b);
		double ans , p = 1.0;
		for(int i = 0 ; i < b; i++)
			p *= (a - 1.0) / a;
		p = 1 - p;
		ans = (a + 1) * p / 2.0 * a;
		printf("Case #%d: %.3lf\n",kase,ans);
	}
    return 0;
}

