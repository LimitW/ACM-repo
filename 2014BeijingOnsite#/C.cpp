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

int T,x,y,x1,y1,x2,y2;

void exgcd(int a,int b,int& d,int& t,int& p){
	if(!b) { d = a; t = 1; p = 0; }
	else { exgcd(b,a%b,d,p,t); p -= t*(a/b); }
}

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a%b);
}

int main(){
	scanf("%d",&T);
	for(int kase = 1; kase <= T; kase++){
		scanf("%d%d",&x,&y);
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		double cx,cy;
		if(x1 == x2 && y1 == y2){
            printf("Case #%d:\n%.1lf %.1lf\n",kase,(double)x1,(double)y1);
            continue;
		}
		else if(x1 == x2){
            double tt = y - (y1+y2)/2.0;
            cy = y- (max(y1,y2)-min(y1,y2))/2.0;
            cx = x1 + tt;
            while(cx > x || cx < 0)
            {
                if(cx > x) cx = x - cx;
                if(cx < 0) cx = -cx;
            }
            printf("Case #%d:\n%.1lf %.1lf\n",kase,cx,cy); continue;
		}
		else if(y1 == y2){
            double tt = x - (x1+x2)/2.0;
            cx = x- (max(x1,x2)-min(x1,x2))/2.0;
            cy = y1 + tt;
            while(cy > x || cy < 0)
            {
                if(cy > y) cy = y - cy;
                if(cy < 0) cy = -cy;
            }
            printf("Case #%d:\n%.1lf %.1lf\n",kase,cx,cy); continue;
		}
		int a,b,c,d,t,p;
		a = 2*x; b = -2*y; c = x1 + x2 - y1 - y2;
		exgcd(a,b,d,t,p);
		int fail = 0;
		if(c % d != 0) fail = 1;
		else{
			t *= c/d; p *= c/d;
			int a2 = a/gcd(a,-b) , b2 = b/gcd(a,-b);
			if(t < 1 && p >= 1){
				while(t < 1){
					t -= b2; p += a2;
				}
				if(p < 1) fail = 1;
			}
			else if(t >= 1 && p < 1){
				while(p < 1){
					t -= b2; p += a2;
				}
				if(t < 1) fail = 1;
			}
			else if(t < 1 && p < 1){
					while(t < 1 || p < 1){
						t -= b2; p += a2;
					}
				}
			else{
				while(t >= 1 && p >= 1){
					t += b2; p -= a2;
				}
				t -= b2; p += a2;
			}
		}
		if(fail) { printf("Case #%d:\nCollision will not happen.\n",kase); }
		else{
			if(x1<x2)swap(x1,x2); if(y1<y2)swap(y1,y2);
			if(t % 2 != 0) cx = x-(x1-x2)/2.0;
			else cx = (-(x-x1)+(x-x2))/2.0;
			if(p % 2 != 0) cy = y-(y1-y2)/2.0;
			else cy = (-(y-y1)+(y-y2))/2.0;
			printf("Case #%d:\n%.1lf %.1lf\n",kase,cx,cy);
		}
	}
	return 0;
}