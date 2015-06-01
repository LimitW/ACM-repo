#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <functional>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>
const int INF = 0x3f3f3f3f;
double a,b,c,d,l,r;

double f(double x){
    return abs(a*x*x*x+b*x*x+c*x+d);
}

int main(){
    while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&l,&r) != EOF)
    {
        double ans = max(f(l),f(r));
        double delta = 4 * b * b - 12 * a * c;
        if(a == 0 && b != 0){
            double x0 = c / (-2) / b ;
            if (x0 < r && x0 > l) ans = max(ans,f(x0));
        }
        else if(a != 0){
            if(delta >= 0){
                double x2 = (sqrt(delta) - 2*b)/(6 * a) , x1 = ( -sqrt(delta) - 2*b)/(6 * a);
                if(x2 < r && x2 > l) ans = max(f(x2),ans);
                if(x1 < r && x1 > l) ans = max(f(x1),ans);
            }
        }
        printf("%.2lf\n",ans);
    }
	return 0;
}
