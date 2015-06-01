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

double dist(long long x1,long long y1,long long x2,long long y2){
	return sqrt ( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
}

int main(){
	int r;
	long long x1,y1,x2,y2;
	scanf("%d%lld%lld%lld%lld",&r,&x1,&y1,&x2,&y2);
	double d = dist(x1,y1,x2,y2);
	if(d == 0)
	{ printf("0\n"); return 0; }
	if(d < 2 * r)
	{ printf("1\n"); return 0; }
	if(d > 2 * r && d <= 4 * r)
	{ printf("2\n"); return 0; }
	if( (int) d == d && (int) (d) % (2 * r) == 0)
	{ printf("%d\n",(int) (d / 2 / r) ); return 0; }
	else{
		printf("%d\n",(int) (d / 2 / r + 1) );
	}
	return 0;
}
