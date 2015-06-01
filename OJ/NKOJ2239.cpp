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
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

const int mod = 2014;

class matrix{
public:
	long long a11 , a12 , a21 , a22;
	matrix(long long a = 1,long long b = 0,long long c = 0,long long d = 1){
		a11 = a ,a12 = b ,a21 = c,a22 = d;
	}
	matrix operator * (matrix b) {
		matrix c;
		c.a11 = (a11 * b.a11 + a12 * b.a21) % mod;
		c.a12 = (a11 * b.a12 + a12 * b.a22) % mod;
		c.a21 = (a21 * b.a11 + a22 * b.a21) % mod;
		c.a22 = (a21 * b.a12 + a22 * b.a22) % mod;
		return c;
	}
};

matrix quickpow(matrix m,int n){
	matrix ans;
	while(n){
		if(n & 1) ans = ans * m;
		n >>= 1; m = m * m;
	}
	return ans;
}

int main(){
	matrix a(3,1,1,0); int n;
	while(scanf("%d",&n) == 1){
		if(n < 3) { printf("1\n"); continue; }
		matrix ans = quickpow(a,n-2);
		printf("%lld\n",(ans.a11+ans.a12)%mod);
	}
	return 0;
}
