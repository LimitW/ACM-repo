#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

int getMonth(char *s){
	if(s[0] == 'J'){
		if(s[1] == 'a') return 1;
		else if(s[1] == 'u' && s[2] == 'n') return 6;
		else return 7;
	}
	else if(s[0] == 'F') return 2;
	else if(s[0] == 'M'){
		if(s[2] == 'r') return 3;
		else return 5;
	}
	else if(s[0] == 'A'){
		if(s[1] == 'p') return 4;
		else return 8;
	}
	else if(s[0] == 'S') return 9;
	else if(s[0] == 'O') return 10;
	else if(s[0] == 'N') return 11;
	else return 12;
}

bool isYr(int y){
	return (y % 100 != 0 && y % 4 == 0) || (y % 400 == 0);
}

struct dt{
	int yr,mt,dy;
};

int main(){
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; kase++){
		char m[12]; dt a,b; int ans = 0;
		scanf("%s %d, %d",m,&a.dy,&a.yr);
		a.mt = getMonth(m);
		if(!(a.mt == 2 && a.dy == 29)){
			if(isYr(a.yr)) {
				if(a.mt > 2){
					a.yr += 4;
					if(!isYr(a.yr)) a.yr += 4;
				}
			}
			else {
				while(!isYr(a.yr)) a.yr++;
			}
		}
		scanf("%s %d, %d",m,&b.dy,&b.yr);
		b.mt = getMonth(m);
		if(!(b.mt == 2 && b.dy == 29)){
			if(isYr(b.yr)){
				if(b.mt < 3){
					b.yr -= 4;
					if(!isYr(b.yr)) b.yr -= 4;
				}
			}
			else{
				while(!isYr(b.yr)) b.yr--;
			}
		}
		if(a.yr > b.yr) { printf("Case #%d: 0\n",kase); continue; }
		ans += (b.yr - a.yr) / 4 + 1;
		while(b.yr % 100 != 0) b.yr -= 4;
		while(a.yr % 100 != 0) a.yr += 4;
		if(b.yr >= a.yr) ans =  ans - (b.yr - a.yr) / 100 - 1;
		while(b.yr % 400 != 0) b.yr -= 4;
		while(a.yr % 400 != 0) a.yr += 4;
		if(b.yr >= a.yr) ans = ans + (b.yr - a.yr) / 400 + 1;
		printf("Case #%d: %d\n",kase,ans);
	}
    return 0;
}

