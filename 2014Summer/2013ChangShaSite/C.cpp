/*
 * Title:Collision
 * Author:LimitW
 * Date:2014.7.28
 * Source:2013 ChangShaSite C
 * Note:计算几何 情况要分清
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

int main(){
	double Rm,R,r,x,y,vx,vy;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf",&Rm,&R,&r,&x,&y,&vx,&vy) != EOF){
		double B=2*vx*x+2*vy*y;
		double A=vx*vx+vy*vy;
		double Cm=x*x+y*y-(r+Rm)*(r+Rm);
		double Cr=x*x+y*y-(r+R)*(r+R);
		double deltam = B*B-4*A*Cm;
		double deltar = B*B-4*A*Cr;
		double t;
		if(deltar <= 0 || A == 0){
			t = 0;
		}
		if(deltar > 0){
			double root_tr = sqrt(deltar);
			double tr1 = ((-1)*B-sqrt(deltar))/(2*A);
			double tr2 = ((-1)*B+sqrt(deltar))/(2*A);
			if(tr1 >= 0){
			// 与round有接触
			    if(deltam <= 0){//与medal无接触
				   t = tr2 - tr1;
				}
				if(deltam > 0){
					double root_tm = sqrt(deltam);
					t = (root_tr - root_tm) / A;
				}
			}
			else 
				t = 0;
		}
		printf("%.3lf\n",t);
	}
	return 0;
}