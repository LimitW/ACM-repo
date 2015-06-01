/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.8.21
 * Source:AOAPC I
 * Note:集合上的dp 状态压缩
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

const double INF = 0x3f3f3f3f;

struct point
{
	double x,y,z;
}p[21];
//double d[21][1<<20];
double d[1<<20];

double dist(point i,point j){
	return sqrt((i.x - j.x)*(i.x - j.x) + (i.y - j.y)*(i.y - j.y) + (i.z - j.z)*(i.z - j.z));
}

/*O(n^2 * 2^n)
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y >> p[i].z;
	for(int i = 0; i < n; i++)
		for(int S = 0; S < (1 << n); S++){
			if(S == 0) d[i][S] = 0;
			else d[i][S] = INF;
			if(S & (1 << i)){
				for(int j = 0; j < i; j++)
					if(S & (1 << j))
						d[i][S] = min( dist(p[i],p[j])+d[i-1][S^(1<<i)^(1<<j)] , d[i][S] );
			}
			else if(i > 0){
				d[i][S] = d[i-1][S];
			}
		}
	printf("%.3lf\n",d[n-1][(1<<n)-1]);
	return 0;
}*/

//O(n*2^n)
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y >> p[i].z;
	d[0] = 0;
	for(int s = 1; s < (1 << n); s++){
		int i,j;
		d[s] = INF;
		for(i = n - 1; i >= 0; i--)
			if(s & (1<<i)) break;
		for(j = i - 1; j >= 0; j--)
			if(s & (1<<j))
				d[s] = min( d[s] , dist(p[i],p[j])+d[s^(1<<i)^(1<<j)] );
		}
	printf("%.3lf\n", d[(1<<n)-1]);
	//system("pause");
	return 0;
}