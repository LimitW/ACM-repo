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
const long long INFL = 1LL << 62;
struct point{
	long long x,y;
	long long od(point b){
		return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
	}
	long long md(point b){
		return abs(x - b.x) + abs(y - b.y);
	}
};

point a[1010];
point b[110];

int main(){
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; kase++){
		int N,M,A,B; scanf("%d%d%d%d",&N,&M,&A,&B);
		long long xc = 0 , yc = 0;
		for(int i = 0; i < A + B; ++i){
			if(i < A){
				scanf("%lld%lld",&a[i].x,&a[i].y);
				xc += a[i].x; yc += a[i].y;
			}
			else scanf("%lld%lld",&b[i-A].x,&b[i-A].y);
		}
		xc /= A; yc /= A;
		long long ans = INFL;
		for(int dx = -50; dx <= 50; ++dx)
			for(int dy = -50; dy <= 50; ++dy){
				point c; long long cur = 0 , cur2 = INF;
				c.x = xc + dx , c.y = yc + dy;
				if(c.x <= 0 || c.x > N || c.y <= 0 || c.y > M) continue;
				for(int i = 0; i < A; ++i){
					cur += c.od(a[i]);
				}
				for(int i = 0; i < B; ++i){
					cur2 = min(cur2,c.md(b[i]));
				}
				ans = min(ans,cur+cur2);
			}
		printf("Case #%d: %lld\n",kase,ans);
	}
    return 0;
}

