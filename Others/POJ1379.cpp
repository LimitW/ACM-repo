/************************************************
 * Title:
 * Author:LimitW
 * Date: 2015-1-27
 * Source: POJ1379
 * Note: Simulate Anneal
*************************************************/
// eps 1e-4 , 1797ms
 
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
#include <utility>
#include <bitset>
#include <algorithm>
#include <ctime>

using namespace std;

const int INF = 0x3f3f3f3f;
const double eps =  1e-4;
const double pi = acos(-1.0);
const int L = 60;
int n;

struct point
{
	double x,y,v;
}p[1010],init[30];

double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double val(point x){
	double ans = INF;
	for(int i = 0; i < n; i++)
		ans = min(ans,dist(p[i],x));
	return ans;
}

bool Accept(double dE,double T){
    return exp(dE / T) > (rand() % 10001)/ 10000.0;
}

int main(){
    srand(time(NULL));
	int T; scanf("%d",&T);
	for(int kase = 0; kase < T; kase++){
		double x,y; scanf("%lf%lf%d",&x,&y,&n);
		for(int i = 0; i < n; i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		for(int i = 0; i < 30; i++){
			init[i].x = (rand()%1000 + 1) / 1000.0 * x;
			init[i].y = (rand()%1000 + 1) / 1000.0 * y;
			init[i].v = val(init[i]);
		}
		double delta = sqrt(x*x+y*y)*0.5;
		while(delta > eps)
		{
			for(int i = 0; i < 30; i++)
			{
			    for(int j = 0; j < L; j++)
                {
                    double rad = 2 * pi * (rand() % 101)/100.0;
                    point tmp;
                    tmp.x = init[i].x + delta * sin(rad);
                    tmp.y = init[i].y + delta * cos(rad);
                    tmp.v = 0;
                    if(tmp.x > x || tmp.x < 0 || tmp.y > y || tmp.y < 0)
                        continue;
                    tmp.v = val(tmp);
                    if(tmp.v > init[i].v || Accept(tmp.v-init[i].v,delta))
                        init[i] = tmp;
                }
            }
            delta *= 0.8;
		}
		point ans; ans.v = 0;
		for(int i = 0; i < 30; i++)
			if(ans.v < init[i].v)
				ans = init[i];
		printf("The safest point is (%.1lf, %.1lf).\n",ans.x,ans.y);
	}
	return 0;
}