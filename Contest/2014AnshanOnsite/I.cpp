//============================================================================
// Name        : I.cpp
// Author      : LimitW
// Version     :
// Copyright   : 2014 Anshan Onsite I
// Description : 
//============================================================================


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

const int maxn = 1e3+10;

double t[maxn],x[maxn],y[maxn];

double dist(double x1,double y1,double x2,double y2)
{
	return sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf",&t[i],&x[i],&y[i]);
		}
		double ma = -1;
		for(int i = 0; i < n - 1; i++)
		{
			ma = max(dist(x[i],y[i],x[i+1],y[i+1])/(t[i+1]-t[i]) , ma);
		}
		printf("%.9lf\n",ma);
	}
	return 0;
}



