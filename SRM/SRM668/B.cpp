#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);

struct point{
	double x,y;
	point(double xx = 0,double yy = 0){
		x = xx; y = yy;
	}
	point operator - (point b) const {
		return point(x-b.x,y-b.y);
	}
}p[4];

double dist(point a,point b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

double pduct(point a,point b){
	return a.x * b.x + a.y * b.y;
}

bool isline(point a,point b){
	return a.x * b.y == a.y * b.x;
}

bool check(){
    point m;
	for(int i = 0; i < 4; ++i){
		m.x += p[i].x;
		m.y += p[i].y;
	}
	m.x /= 4.0; m.y /= 4.0;
    if(dist(m, p[0]) == 0) return false;
    for(int i = 0; i < 4; i++) {
        if (dist(m, p[i]) != dist(m, p[0])) {
        	return false;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (dist(p[i], p[j]) == 0) return false;
            if (pduct(p[i]-m,p[j]-m) != 0 && !isline(p[i]-m,p[j]-m))
            	return false;
        }
    }
    return true;
}

string a = "It's a square",
		b = "Not a square";

class IsItASquare{
public:
	string isSquare(vector <int> x, vector <int> y){
		for(int i = 0; i < 4; ++i){
			p[i].x = (double)x[i];
			p[i].y = (double)y[i];
		}
		if(check()) return a;
		else return b;
	}
};
