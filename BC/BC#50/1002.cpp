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

const double pi = acos(-1.0);

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 30 + 3;
const int maxm = 100 + 3;
const double eps = 1e-9;

struct point{
	double x,y;
	point(double xx = 0,double yy = 0){
		x = xx; y = yy;
	}
	point operator - (point b) const {
		return point(x - b.x, y - b.y);
	}
}pp[25];

double dist(point a,point b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

double pduct(point a,point b){
	return a.x * b.x + a.y * b.y;
}

bool isline(point a,point b){
	return a.x * b.y == a.y * b.x;
}

bool check(int n,point p[]){
    point m;
	for(int i = 0; i < n; ++i){
		m.x += p[i].x;
		m.y += p[i].y;
	}
	m.x /= n * 1.0; m.y /= n * 1.0;
    if(dist(m, p[0]) == 0) return false;
    for(int i = 1; i < n; i++) {
        if (dist(m, p[i]) != dist(m, p[0])) {
        	return false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(p[i], p[j]) == 0) return false;
            	if (pduct(p[i] - m, p[j] - m) != 0 && !isline(p[i] - m, p[j] - m))
			return false;
        }
    }
    return true;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf",&pp[i].x,&pp[i].y);
		}
		int res = 0;
		for(int a1 = 0; a1 < n; ++a1)
			for(int a2 = a1 + 1; a2 < n; ++a2)
				for(int a3 = a2 + 1; a3 < n; ++a3)
					for(int a4 = a3 + 1; a4 < n; ++a4){
						point p[4];
						p[0] = pp[a1], p[1] = pp[a2], p[2] = pp[a3], p[3] = pp[a4];
						if(check(4,p)) ++res;
					}
		cout << res << '\n';
	}
	return 0;
}

