/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.9.13
 * Source:Codeforces Round 266 B
 * Note:
*************************************************/

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

const long long INF = 6e9+10;

int main(){
	long long n,a,b;
	cin >> n >> a >> b;
	long long s = 6*n;
	long long a1 = a, b1 = b;
	if(a1*b1 > 6*n)
	{
		printf("%I64d\n",a1*b1);
		printf("%I64d %I64d\n",a1,b1);
		return 0;
	}
	long long s1 = INF;
	long long x = ceil( (double) s / a1 );
	if(x >= b1){
		s1 = x * a1;
		b1 = x;
	}
	long long s2 = INF;
	long long y = ceil( (double) s / b1 );
	if(y >= a1){
		s2 = y * b1;
		if(s1 > s2){
			s1 = s2;
			a1 = y; b1 = b;
		}
	}
	long long s3 = INF;
	long long minl = ceil(sqrt(s));
	if(a1 < minl && b1 < minl){
		s3 = minl * minl;
		if(s1 < s3){
			s1 = s3;
			a1 = minl; b1 = minl;
		}
	}
	printf("%I64d\n",a1*b1);
	printf("%I64d %I64d\n",a1,b1);
	//system("pause");
	return 0;
}
