/*
 * Title:Running Rabbits
 * Author:LimitW
 * Date:2014.8.18
 * Source:2012 JinHuaSite K
 * Note:模拟 水题
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

const int dir[4][2] = {0,-1,0,1,-1,0,1,0};

int n;

struct p{
	int x,y;
	int s; int t; int d;
}ra[2];

int change_d(int d){
	switch(d){
		case 0:return 1;
		case 1:return 0;
		case 2:return 3;
		case 3:return 2;
	}
}

int get_d(char c){
	switch(c){
		case 'N':return 0;
		case 'S':return 1;
		case 'W':return 2;
		case 'E':return 3;
	}
}

int turn_left(int d){
	switch(d){
		case 0:return 2;
		case 1:return 3;
		case 2:return 1;
		case 3:return 0;
	}
}

int is_valid(int x){
	return (x >= 1 && x <= n);
}

p get_step(p ra1){
	int dx = ra1.x + ra1.s*dir[ra1.d][0];
	int dy = ra1.y + ra1.s*dir[ra1.d][1];
	if(is_valid(dx) && is_valid(dy)) { ra1.x = dx; ra1.y = dy; }
	else if(!is_valid(dx)){
		int res = abs(ra1.s*dir[ra1.d][0]);
		while(!is_valid(dx)){
			if(dx < 1){
				res -= (res+dx-1);
				dx = 1;
				ra1.d = change_d(ra1.d);
			}
			if(dx > n){
				res = (dx - n);
				dx = n;
				ra1.d = change_d(ra1.d);
			}
			dx += res*dir[ra1.d][0];
		}
	}
	else{
		int res = abs(ra1.s*dir[ra1.d][1]);
		while(!is_valid(dy)){
			if(dy < 1){
				res -= (res+dy-1);
				dy = 1;
				ra1.d = change_d(ra1.d);
			}
			if(dy > n){
				res = (dy - n);
				dy = n;
				ra1.d = change_d(ra1.d);
			}
			dy += res*dir[ra1.d][1];
		}
	}
	ra1.x = dx; ra1.y = dy;
	return ra1;
}

int is_meet(p ra1,p ra2){
	return (ra1.x == ra2.x && ra1.y == ra2.y);
}

int main(){
	while(cin>>n && n){
		ra[0].x = 1; ra[0].y = 1;
		ra[1].x = n; ra[1].y = n;
		char c; int s; int t;
		int i;
		for(i=0;i<2;i++){
			cin>>c>>s>>t;
			ra[i].d = get_d(c);
			ra[i].s = s; ra[i].t = t;
		}
		int K;
		cin>>K;
		ra[0] = get_step(ra[0]);
		ra[1] = get_step(ra[1]);
		for(i=1;i<K;i++){
            int meet_flag = 0;
            if(is_meet(ra[0],ra[1])){
				int tmp = ra[0].d;
				ra[0].d = ra[1].d;
				ra[1].d = tmp;
				meet_flag = 1;
 			}
			int j;
			for(j=0;j<2;j++){
                if(i % ra[j].t == 0 && !meet_flag)
                    ra[j].d = turn_left(ra[j].d);
				ra[j] = get_step(ra[j]);
			}
		}
		printf("%d %d\n",ra[0].y,ra[0].x);
		printf("%d %d\n",ra[1].y,ra[1].x);
 	}
	return 0;
}