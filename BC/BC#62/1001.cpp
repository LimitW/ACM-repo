#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-4;

int dcmp(double x){
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

struct point{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    bool operator == (const point& rhs) const {
        return dcmp(x-rhs.x) == 0 && dcmp(y - rhs.y) == 0;
    }
    bool operator < (const point& rhs) const {
        return dcmp(x-rhs.x) < 0 || (dcmp(x-rhs.x)==0 && dcmp(y-rhs.y)<0);
    }
};

double dist(point a, point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

typedef point Vector;

Vector operator-(point A, point B){
    return Vector(A.x - B.x, A.y - B.y);
}

double Cross(Vector A,Vector B){
    return A.x * B.y - A.y * B.x;
}

point p[5], ch[5];

int ConvexHull(int n){
    sort(p, p + n);
    n = unique(p, p + n) - p;
    int m = 0;
    for(int i = 0; i < n; ++i){
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) < 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n - 2; i >= 0; --i){
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) < 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    return m;
}

bool check(){
    int m = ConvexHull(5);
    if(m != 5) return 0;
    point c; c.x = 0, c.y = 0;
    for(int i = 0; i < 5; ++i){
        c.x += p[i].x;
        c.y += p[i].y;
    }
    c.x /= 5, c.y /= 5;
    double d = dist(c, p[0]);
    for(int i = 1; i < 5; ++i)
         if(fabs(d - dist(c, p[i])) >= eps) return 0;
    for(int i = 1; i < 5; ++i){
        Vector X = ch[i] - c;
        Vector Y = ch[i-1] - c;
        double dot = X.x * Y.x + X.y * Y.y;
        double res = dist(ch[i], c) * cos(72.0 / 180.0 * acos(-1.0)) * dist(ch[i], c);
        if(fabs(dot - res) >= eps) return 0;
    }
    return 1;
}

int main(){
    int T; scanf("%d", &T);
    while(T--){
        bool flag = 1;
        for(int i = 0; i < 5; ++i){
            scanf("%lf%lf", &p[i].x, &p[i].y);
            if(!(p[i] == p[0])) flag = 0;
        }
        if(flag) puts("Yes");
        else puts(check() ? "Yes" : "No");
    }
    return 0;
}
