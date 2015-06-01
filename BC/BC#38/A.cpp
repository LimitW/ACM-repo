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
	long long x,y,z;
	bool operator == (point b) const {
		return x == b.x && y == b.y && z == b.z;
	}
	point operator - (point b) const{
		point c; c.x = x - b.x; c.y = y - b.y; c.z = z - b.z;
		return c;
	}
	long long pt(point b){
		return x * b.x + y * b.y + z * b.z;
	}
	long long dis(point b){
		return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y) + (z - b.z) * (z - b.z);
	}
};

bool is_ok(point a,point b,point c,point d){
	if((a-b).pt(b-c) == 0 && (b-c).pt(c-d) == 0 && (c-d).pt(d-a) == 0 && (d-a).pt(a-b) == 0 && a.dis(b) == b.dis(c) && b.dis(c) == c.dis(d) && c.dis(d) == d.dis(a) )
				return 1;
	else return 0;
}

int main(){
	int T; scanf("%d",&T);
	for(int kase = 1; kase <=T ; ++kase){
		point a,b,c,d;
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&a.x,&a.y,&a.z,&b.x,&b.y,&b.z,&c.x,&c.y,&c.z,&d.x,&d.y,&d.z);
		if(is_ok(a,b,c,d) || is_ok(a,c,b,d) || is_ok(a,c,d,b) ||
				is_ok(a,d,b,c) || is_ok(a,b,d,c) || is_ok(a,d,c,b) || is_ok(d,a,b,c)
	|| is_ok(d,a,c,b) || is_ok(d,b,c,a) || is_ok(d,b,a,c) || is_ok(d,c,a,b) || is_ok(d,c,b,a)
	|| is_ok(b,a,c,d) || is_ok(b,a,d,c) || is_ok(b,c,a,d) || is_ok(b,c,d,a) || is_ok(b,d,a,c) || is_ok(b,d,c,a) ||
	is_ok(c,a,b,d) || is_ok(c,a,d,b) || is_ok(c,b,d,a) || is_ok(c,b,a,d) || is_ok(c,d,a,b) || is_ok(c,d,b,a))
			printf("Case #%d: Yes\n",kase);
		else printf("Case #%d: No\n",kase);
	}
    return 0;
}

