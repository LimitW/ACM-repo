/*
 * Title:Pashmak and Garden
 * Author:LimitW
 * Date:2014.8.16
 * Source:codeforces round 261 B
 * Note:水题
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
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

int main(){
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2;
	if(x1 == x2 && y1 != y2){
		int dy = abs(y1 - y2);
		x3 = x1 + dy;
		x4 = x2 + dy;
		y3 = y1;
		y4 = y2;
	}
	if(x1 != x2 && y1 == y2){
		int dx = abs(x1 - x2);
		y3 = y1 + dx;
		y4 = y2 + dx;
		x3 = x1;
		x4 = x2;
	}
	if(x1 != x2 && y1 != y2){
		int dx = abs(x1 - x2);
		int dy = abs(y1 - y2);
		if(dx != dy){
			cout<<-1<<endl;
			return 0;
		}
		else{
			x3 = x2;
			y3 = y1;
			x4 = x1;
			y4 = y2;
		}
	}
	cout<<x3<<' '<<y3<<' '<<x4<<' '<<y4<<endl;
	return 0;
}