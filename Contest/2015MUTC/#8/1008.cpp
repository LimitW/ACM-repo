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
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 3;
//const int maxm = maxn * maxn;

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a%b);
}

void print(int a,int b){
	int p = abs(a - b), q = 3600;
	if( (double)(p) / q > 180.0){
		p = 360 * 3600 - p;
	}
	if(p == 0) printf("0 ");
	else{
		int x = gcd(p,q);
		p /= x, q /= x;
		if(q == 1) printf("%d ", p);
		else printf("%d/%d ", p ,q);
	}
}

int main(){
	char k[15];
	int T; scanf("%d", &T);
 	while(T--){
		scanf("%s", k);
		int h = (k[0] - '0') * 10 + (k[1] - '0');
		h %= 12;
		int m = (k[3] - '0') * 10 + (k[4] - '0');
		int s = (k[6] - '0') * 10 + (k[7] - '0');
		int a = 30 * (60 * m + s + 3600 * h);
		int b = 6 * (60 * s + 3600 * m);
		int c = 3600 * 6 * s;
		print(a,b);
		print(a,c);
		print(b,c);
		puts("");
	}
    return 0;
}

